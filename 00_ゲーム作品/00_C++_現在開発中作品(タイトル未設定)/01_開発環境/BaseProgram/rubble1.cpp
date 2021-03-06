//=============================================================================CRubble
//
// 瓦礫クラス [rubble1.cpp]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "rubble1.h"
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "texture.h"
#include "resource_manager.h"
#include "xfile.h"
#include "model_info.h"
#include "player.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define TEST_POS    (D3DXVECTOR3(-28380.7f, 0.0f, 9440.9f))
#define TEST_ROT    (D3DXVECTOR3(0.0f, D3DXToRadian(-45.0f), 0.0f))

//=============================================================================
// コンストラクタ
//=============================================================================
CRubble1::CRubble1(PRIORITY Priority) : CModel(Priority)
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CRubble1::~CRubble1()
{
}

//=============================================================================
// インスタンス生成
//=============================================================================
CRubble1 * CRubble1::Create()
{
    // メモリ確保
    CRubble1 *pTestModel = new CRubble1(PRIORITY_TEST_MODEL);

    // !nullcheck
    if (pTestModel)
    {
        // 初期化処理
        pTestModel->Init();
        return pTestModel;
    }

    return nullptr;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CRubble1::Init()
{
    // 初期化処理
    CModel::Init();

    CXfile *pXfile = GET_XFILE_PTR;
    CXfile::MODEL model = pXfile->GetXfile(CXfile::XFILE_NUM_MOVE_RUBBLE1);
    GetModelInfo()->SetModelStatus(TEST_POS, TEST_ROT, model);

    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CRubble1::Uninit()
{
    CModel::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CRubble1::Update()
{
    CModel::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CRubble1::Draw()
{
    CModel::Draw();
}