//=============================================================================
//
// フェード処理 [fade.h]
// Author : Suzuki Mahiro
//
//=============================================================================

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "fade.h"
#include "scene2d.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
//マクロ定義
//*****************************************************************************
#define ALPHA_FLUCTUATION (0.02f)	//透明度の変動量

//*****************************************************************************
//静的メンバ変数宣言
//*****************************************************************************
LPDIRECT3DTEXTURE9 CFade::m_pTexture = NULL;
CManager::MODE CFade::m_mode = CManager::MODE_NONE;
CFade::FADE CFade::m_FadeStatus = FADE_NONE;

//*****************************************************************************
//コンストラクタ
//*****************************************************************************
CFade::CFade(OBJTYPE Priority) :CScene2D(Priority)
{
	m_pVtxBuff = NULL;
}

//*****************************************************************************
//デストラクタ
//*****************************************************************************
CFade::~CFade()
{
}

//*****************************************************************************
//初期化処理
//*****************************************************************************
HRESULT CFade::Init(void)
{
	//位置の設定
	SetPos(SCREEN_CENTER);

	//シーン2Dの初期化処理
	CScene2D::Init();

	return S_OK;
}

//*****************************************************************************
//終了処理
//*****************************************************************************
void CFade::Uninit(void)
{
	//シーン2Dの終了処理
	CScene2D::Uninit();
}

//*****************************************************************************
//更新処理
//*****************************************************************************
void CFade::Update(void)
{
	if (m_FadeStatus != FADE_NONE)
	{
		if (m_FadeStatus == FADE_IN)
		{ //フェード状態がフェードインのとき
			//フェードイン処理
			FadeIn();
		}
		else if (m_FadeStatus == FADE_OUT)
		{ //フェード状態がフェードアウトのとき
			//フェードアウト処理
			FadeOut();
		}

		//シーン2Dの更新処理
		CScene2D::Update();
	}
}

//*****************************************************************************
//描画処理
//*****************************************************************************
void CFade::Draw(void)
{
	//シーン2Dの描画処理
	CScene2D::Draw();
}

//*****************************************************************************
//フェードイン処理
//*****************************************************************************
void CFade::FadeIn(void)
{
	//色の取得
	D3DXCOLOR col = GetCol();

	//透明度の加算
	col.a += ALPHA_FLUCTUATION;

	if (col.a >= FLOAT_ONE)
	{ //透明度がFLOAT_ONEを超えたとき
		//透明度をFLOAT_ONEにする
		col.a = FLOAT_ONE;

		//フェード状態をフェードアウトに設定
		m_FadeStatus = FADE_OUT;

		//モードの設定
		GetManager()->SetMode(m_mode);
	}

	//色の設定
	SetCol(col);
}

//*****************************************************************************
//フェードアウト処理
//*****************************************************************************
void CFade::FadeOut(void)
{
	//色の取得
	D3DXCOLOR col = GetCol();

	//透明度の減算
	col.a -= ALPHA_FLUCTUATION;

	if (col.a <= FLOAT_ZERO)
	{ //透明度がFLOAT_ZEROを下回ったとき
		//透明度をFLOAT_ZEROにする
		col.a = FLOAT_ZERO;

		//フェード状態をFADE_NONEにする
		m_FadeStatus = FADE_NONE;

		if (m_mode == CManager::MODE_GAME)
		{ //ゲームシーンに遷移するとき
			//指定したOBJTYPEのみを更新する
			SetUpdateType(OBJTYPE_UI_START, NULL);
		}
		else
		{ //それ以外のとき
			//指定したOBJTYPEのみを更新する
			SetUpdateType(OBJTYPE_MAX, NULL);
		}

		return;
	}

	//色の設定
	SetCol(col);
}

//*****************************************************************************
//フェードの設定処理
//*****************************************************************************
void CFade::SetFade(CManager::MODE mode)
{
	//指定したOBJTYPEのみを更新する
	SetUpdateType(OBJTYPE_FADE, NULL);

	//フェード情報の設定
	SetPos(SCREEN_CENTER);
	SetSize(SCREEN_SIZE);
	SetCol(ZeroColor);
	SetObjType(CScene::OBJTYPE_FADE);
	m_FadeStatus = FADE_IN;
	m_mode = mode;
}