//=============================================================================
//
// メッセージ表示処理 [message.h]
// Author : Suzuki Mahiro
//
//=============================================================================
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

//*****************************************************************************
//ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"
#include "scene.h"
#include "ui.h"
#include "manager.h"

//*****************************************************************************
//前方宣言
//*****************************************************************************
class CFade;

//*****************************************************************************
//クラス定義
//*****************************************************************************
class CMessage :public CScene
{
public:
	CMessage();
	~CMessage();
	static CMessage *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nTime, CUi::UI_TYPE type, CManager::MODE mode);
	HRESULT Init(void);
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nTime, CUi::UI_TYPE type, CManager::MODE mode);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	CUi *m_pUi;				//UIのポインタ
	CFade *m_pFade;			//フェードのポインタ
	int m_nCounter;			//メッセージ表示時間のカウント
	int m_nTime;			//タイムの保存用
	CManager::MODE m_mode;	//モードの保存用
};

#endif