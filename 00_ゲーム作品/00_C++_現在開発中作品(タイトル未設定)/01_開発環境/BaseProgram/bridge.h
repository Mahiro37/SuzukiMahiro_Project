#ifndef _BRIDGE_H_
#define _BRIDGE_H_
//=============================================================================
//
// 橋クラス [bridge.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=========================================================================
// インクルード
//=========================================================================
#include "model.h"

//=========================================================================
// 前方宣言
//=========================================================================
class CCollisionModelOBB;

//=========================================================================
// クラス定義
//=========================================================================
class CBridge : public CModel
{
public:
    CBridge(PRIORITY = PRIORITY_TEST_MODEL);    // コンストラクタ
    ~CBridge();                                 // デストラクタ

    static CBridge *Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &rot); // インスタンス生成
    HRESULT Init(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &rot);           // 初期化処理
    void Update();                                                          // 更新処理

    void HitOBBs(); // OBB同士の当たり判定

private:
    CCollisionModelOBB* m_pColModelOBB; // 当たり判定ポインタ
};

#endif