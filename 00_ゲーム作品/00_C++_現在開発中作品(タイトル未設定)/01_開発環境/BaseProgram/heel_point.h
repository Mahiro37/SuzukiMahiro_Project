#ifndef _HEEL_POINT_H_
#define _HEEL_POINT_H_
//=============================================================================
//
// 回復ポイントクラス [heel_point.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=========================================================================
// インクルード
//=========================================================================
#include "model.h"

//=========================================================================
// クラス定義
//=========================================================================
class CHeelPoint : public CModel
{
public:
    CHeelPoint(PRIORITY = PRIORITY_TEST_MODEL); // コンストラクタ
    ~CHeelPoint();                              // デストラクタ

    static CHeelPoint *Create(const D3DXVECTOR3 &pos);  // インスタンス生成
    HRESULT Init(const D3DXVECTOR3 &pos);               // 初期化処理
    void Draw();                                        // 描画処理
    bool Collision();                                   // 当たり判定
    D3DXVECTOR3 GetPos();                               // 座標の取得
private:

};

#endif