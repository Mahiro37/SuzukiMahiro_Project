//=============================================================================
//
// テストモデルクラス [test_model.cpp]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "test_model.h"
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "texture.h"
#include "resource_manager.h"
#include "xfile.h"
#include "model_info.h"
#include "player.h"
#include "collisionModel_OBB.h"
#include "collision.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define TEST_POS        (ZeroVector3)
#define TEST_ROT        (ZeroVector3)

//=============================================================================
// コンストラクタ
//=============================================================================
CTestModel::CTestModel(PRIORITY Priority) : CModel(Priority)
{
    m_pCollisionModelOBB = nullptr;
}

//=============================================================================
// デストラクタ
//=============================================================================
CTestModel::~CTestModel()
{
}

//=============================================================================
// インスタンス生成
//=============================================================================
CTestModel * CTestModel::Create()
{
    // メモリ確保
    CTestModel *pTestModel = new CTestModel(PRIORITY_TEST_MODEL);

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
HRESULT CTestModel::Init()
{
    // 初期化処理
    CModel::Init();

    CXfile *pXfile = GET_XFILE_PTR;
    CXfile::MODEL model = pXfile->GetXfile(CXfile::XFILE_NUM_MAP);
    GetModelInfo()->SetModelStatus(TEST_POS, TEST_ROT, model);

    //当たり判定モデルの生成
    if (!m_pCollisionModelOBB)
    {
        //m_pCollisionModelOBB = CCollisionModelOBB::Create(GetModelInfo()->GetPos(), D3DXVECTOR3(5000.0f, 100.0f, 4200.0f), TEST_ROT);
    }

    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTestModel::Uninit()
{
    CModel::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CTestModel::Update()
{
    CModel::Update();

    // 衝突判定
    HitOBBs();
    Hit();
}

//=============================================================================
// 描画処理
//=============================================================================
void CTestModel::Draw()
{
    CModel::Draw();
}

//=============================================================================
// 衝突判定
//=============================================================================
void CTestModel::Hit()
{
    CPlayer* pPlayer = nullptr;
    pPlayer = (CPlayer*)GetTop(PRIORITY_CHARACTER);

    if (pPlayer)
    {
        D3DXVECTOR3 RayDir = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
        BOOL bHit = FALSE;
        FLOAT fDistance = 0.0f;

        for (int nCount = 0; nCount < (int)GetModelInfo()->GetMesh()->GetNumFaces(); nCount++)
        {
            //下方向
            D3DXIntersect(
                GetModelInfo()->GetMesh(),
                &pPlayer->GetPos(),
                &RayDir,
                &bHit,
                nullptr,
                nullptr,
                nullptr,
                &fDistance,
                nullptr,
                nullptr);

            if (bHit && fDistance < 80.0f)
            {
                // 着地の処理
                pPlayer->Landing(pPlayer->GetPos().y + fDistance);

                break;
            }
            else if (!bHit)
            {
                pPlayer->SetLanding(false);
            }
        }
    }

}

//=============================================================================
// OBB同士の当たり判定
//=============================================================================
void CTestModel::HitOBBs()
{
    // プレイヤーポインタの取得
    CPlayer* pPlayer = CManager::GetInstance()->GetPlayer();
    if (!pPlayer)
        return;

    // プレイヤーの当たり判定モデルポインタの取得
    CCollisionModelOBB* pPlayerColModelOBB = pPlayer->GetColOBBPtr();

    if (m_pCollisionModelOBB && pPlayerColModelOBB)
    {
        if (CCollision::ColOBBs(m_pCollisionModelOBB->GetOBB(), pPlayerColModelOBB->GetOBB()))
        {
            // 着地の処理
            pPlayer->Landing(m_pCollisionModelOBB->GetOBB().info.pos.y + (m_pCollisionModelOBB->GetOBB().info.size.y / 2) + (pPlayerColModelOBB->GetOBB().info.size.y / 2));
        }
    }
}