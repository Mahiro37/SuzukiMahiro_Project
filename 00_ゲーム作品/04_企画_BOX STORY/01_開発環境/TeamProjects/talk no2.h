//=============================================================================
//
//	セリフNo.2[talk no2.h]
//	Author:筒井　俊稀
//
//=============================================================================

// 二重インクルード防止
#ifndef _TALK_NO2_H_
#define _TALK_NO2_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "talk_base.h"

//=============================================================================
// 前方宣言
//=============================================================================
class CTutorial;

//=============================================================================
// クラス定義
//=============================================================================
class CTalkNo2 :public CTalkbase
{
public:

	CTalkNo2(int nPriorit = PRIORITY_UI_0);	// コンストラクタ
	static CTalkNo2* Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	HRESULT		Init(void);				// 初期化処理
	void		Update(void);			// 更新処理
	void		Talk(void);				// トークを進める関数

protected:
	bool		m_bTutorial;	//チュートリアル処理スイッチ
	CTutorial*	m_pTutorial;	//チュートリアルポインタ

};
#endif
