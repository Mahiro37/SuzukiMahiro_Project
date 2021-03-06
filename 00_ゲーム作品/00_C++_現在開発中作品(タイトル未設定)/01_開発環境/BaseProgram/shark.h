#ifndef _SHARK_H_
#define _SHARK_H_
//=============================================================================
//
// サメ [shark.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "wimp_enemy.h"

//=============================================================================
// 前方宣言
//=============================================================================
class CSharkModel;

//=============================================================================
// クラス定義
//=============================================================================
class CShark : public CWimpEnemy
{
public:
    CShark(PRIORITY Priority = PRIORITY_CHARACTER); // コンストラクタ
    ~CShark();                                      // デストラクタ

    static CShark *Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &rot);  // インスタンス生成
    HRESULT Init(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &rot);           // 初期化処理
    void Uninit();  // 終了処理
    void Update();  // 更新処理

private:
    // private関数
    void CreateModel(); // モデル生成
    void Attack();      // 攻撃

    // メンバ変数
    CSharkModel *m_pSharkModel; // モデルの変数
    static const float m_fCollisionSize;
};
#endif