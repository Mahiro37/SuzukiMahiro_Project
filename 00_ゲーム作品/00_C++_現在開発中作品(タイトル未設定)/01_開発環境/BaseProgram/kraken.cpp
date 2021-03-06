//=============================================================================
//
// クラーケンクラス [kraken.cpp]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "kraken.h"
#include "animation_skinmesh.h"
#include "skinmesh_model.h"
#include "boss_bullet.h"
#include "collisionModel_OBB.h"
#include "state.h"
#include "state_kraken_normal.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define POS             (D3DXVECTOR3(-16686.5f, 0.0f, -2596.4f))
#define SIZE            (D3DXVECTOR3(3200.0f, 7500.0f, 3200.0f))
#define BULLET_INTERVAL (500)                                      // たま発射間隔
#define MAX_LIFE        (5)                                        // ライフ

//=============================================================================
// コンストラクタ
//=============================================================================
CKraken::CKraken(PRIORITY Priority) : CEnemy(Priority)
{
    m_pSkinmeshModel = nullptr;
    m_nBulletCount = 0;
    m_pCollision = nullptr;
    m_nLife = MAX_LIFE;
    m_bDead = false;
    m_pCurrentState = nullptr;
    m_pNextState = nullptr;
}

//=============================================================================
// デストラクタ
//=============================================================================
CKraken::~CKraken()
{
}

//=============================================================================
// インスタンス生成
//=============================================================================
CKraken * CKraken::Create()
{
    CKraken *pKraken = new CKraken;
    if (pKraken)
    {
        pKraken->Init();
        return pKraken;
    }

    return nullptr;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CKraken::Init()
{
    // モデル情報設定
    SetCharacterInfo(POS, ZeroVector3);
    SetGravityFlag(false);
    CEnemy::Init();

    // モデルの生成
    CreateModel();

    if (!m_pCollision)
    {
        // インスタンス生成
        m_pCollision = CCollisionModelOBB::Create(POS, SIZE, ZeroVector3);
    }

    if (!m_pCurrentState)
    {
        m_pCurrentState = CKrakenStateNormal::Create();
    }
    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CKraken::Uninit()
{
    if (m_pSkinmeshModel)
    {
        m_pSkinmeshModel->Uninit();
        m_pSkinmeshModel = nullptr;
    }
    if (m_pCollision)
    {
        m_pCollision->Uninit();
        m_pCollision = nullptr;
    }

    CEnemy::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CKraken::Update()
{
    CEnemy::Update();
    Attack();
    if (m_pCollision)
    {
        m_pCollision->SetInfo(GetPos(), m_pCollision->GetInfo().size, GetRot());
    }

    // 体力が無くなったら
    if (m_nLife <= 0)
    {
        m_bDead = true;
    }
}

//=============================================================================
// 状態の変更
//=============================================================================
void CKraken::ChangeState(CState* pState)
{
    m_pNextState = pState;
}

//=============================================================================
// モデルの生成
//=============================================================================
void CKraken::CreateModel()
{
    m_pSkinmeshModel = CSkinmeshModel::Create(GetPos(), GetRot(), CSkinmeshModel::MODEL_ENEMY_KRAKEN_HEAD);

    m_pSkinmeshModel->IsDraw(true);

    // モデルの情報分からない
    m_pSkinmeshModel->GetHLcontroller()->ChangeAnimation(0);
    m_pSkinmeshModel->GetHLcontroller()->SetLoopTime(0, 60);
    m_pSkinmeshModel->GetHLcontroller()->SetShiftTime(0, 60);
}

//=============================================================================
// 状態の更新
//=============================================================================
void CKraken::UpdateState()
{
    if (m_pNextState)
    {
        delete m_pCurrentState;
        m_pCurrentState = nullptr;

        m_pCurrentState = m_pNextState;
        m_pNextState = nullptr;
    }

    if (m_pCurrentState)
    {
        // 更新処理
        m_pCurrentState->Update();
    }
}

//=============================================================================
// 攻撃
//=============================================================================
void CKraken::Attack()
{
    UpdateState();
}
