//=============================================================================
//
// ライト処理 [light.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _LIGHT_H_
#define _LIGHT_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "main.h"

//=============================================================================
// クラス定義
//=============================================================================
class CLight
{
public:
    CLight();
    ~CLight();
    void Init(void);
    void Uninit(void);
    void Update(void);

private:
    D3DLIGHT9 m_light;    //カメラ情報
};

#endif
