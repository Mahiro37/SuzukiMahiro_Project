//=============================================================================
//
//	チュートリアル [tutorial.h]
//	Author : 鈴木　聖大
//
//=============================================================================

//二重インクルード防止
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

//====================================
//インクルード
//====================================
#include "main.h"
#include "ui.h"

//====================================
// クラス定義
//====================================

//UIクラス
class CTutorial : public CUi
{
public:
	CTutorial(int nPriorit = PRIORITY_UI_0);
	~CTutorial();

	static CTutorial *Create(void);
	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void TutorialUninit(void);
private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	CObject2D* m_pObject2d;
};
#endif // !_UI_H_