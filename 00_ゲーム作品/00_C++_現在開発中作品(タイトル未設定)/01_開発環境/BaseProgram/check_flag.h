#ifndef _CHECK_FLAG_H_
#define _CHECK_FLAG_H_
//=============================================================================
//
// テストモデルクラス [check_flag.h]
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
class CCheckFlag : public CModel
{
public:
	CCheckFlag(PRIORITY = PRIORITY_TEST_MODEL);			// コンストラクタ
	~CCheckFlag();										// デストラクタ

	static CCheckFlag *Create(const D3DXVECTOR3 &pos);	// インスタンス生成
	HRESULT Init(const D3DXVECTOR3 &pos);				// 初期化処理
	bool Collision();									// 当たり判定
	D3DXVECTOR3 GetPos();								// 座標の取得
private:

};

#endif