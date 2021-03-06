//=============================================================================
//
// シャドウポリゴンクラス [shadow_polygon.cpp]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "manager.h"
#include "renderer.h"
#include "shadow_polygon.h"
#include "shadow.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define SHADOW_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f))
#define SHADOW_SIZE (D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f))

//=============================================================================
// コンストラクタ
//=============================================================================
CShadowPolygon::CShadowPolygon(PRIORITY Priority) : CScene2D(Priority)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CShadowPolygon::~CShadowPolygon()
{
}

//=============================================================================
// インスタンス生成
//=============================================================================
CShadowPolygon * CShadowPolygon::Create()
{
    // メモリ確保
    CShadowPolygon *pPolygon = new CShadowPolygon(PRIORITY_SHADOW);

    // !nullcheck
    if (pPolygon)
    {
        // 初期化処理
        pPolygon->Init();

        return pPolygon;
    }

    return nullptr;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CShadowPolygon::Init()
{
    // シーンの情報設定
    SetSceneInfo(SHADOW_POS, SHADOW_SIZE);

    // 初期化処理
    CScene2D::Init();

    // 色の設定
    SetColor(D3DCOLOR_RGBA(0, 0, 0, 0x7f));

    return S_OK;
}

//=============================================================================
// 影の描画
//=============================================================================
void CShadowPolygon::Draw()
{
    // ステンシルテスト
    CShadow::SetShadowStencilTest();

    // ポリゴンの描画
    CScene2D::Draw();

    // ステンシルリセット
    CShadow::ReSetShadowStateStencil();
}