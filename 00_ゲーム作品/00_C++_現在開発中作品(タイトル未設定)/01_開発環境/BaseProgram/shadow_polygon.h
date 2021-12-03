#ifndef _SHADOW_POLYGON_H_
#define _SHADOW_POLYGON_H_
//=============================================================================
//
// 影用ポリゴンクラスヘッダー [shadow_polygon.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=========================================================================
// インクルード
//=========================================================================
#include "scene2d.h"

//=========================================================================
// 前方宣言
//=========================================================================

//=========================================================================
// クラス定義
//=========================================================================
class CShadowPolygon : public CScene2D
{
public:
    CShadowPolygon(PRIORITY = PRIORITY_SHADOW);    // コンストラクタ
    ~CShadowPolygon();                            // デストラクタ

    static CShadowPolygon *Create();    // インスタンス生成
    HRESULT Init();                        // 初期化処理
    void Draw();                        // 描画処理

private:
};

#endif
