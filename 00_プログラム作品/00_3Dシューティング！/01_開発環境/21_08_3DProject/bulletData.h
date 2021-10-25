//=============================================================================
//
// 弾データ管理 [bulletData.h]
// Author : Suzuki Mahiro
//
//=============================================================================
#ifndef _BULLET_DATA_H_
#define _BULLET_DATA_H_

//*****************************************************************************
//インクルードファイル
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define BULLET_MAX (5)	//弾の種類の最大数

//*****************************************************************************
//クラス定義
//*****************************************************************************
class CBulletData
{
public:
	//弾情報の構造体
	struct CreateInfo
	{
		int nType;					//種類
		D3DXVECTOR3 distance;		//生成位置(プレイヤーの中心からの距離)
		D3DXVECTOR3 modelSize;		//モデルの大きさ
		D3DXVECTOR3 collisionSize;	//当たり判定の大きさ
		float fMove;				//移動量
		int nLife;					//反射数
	};

	CBulletData();	//コンストラクタ
	~CBulletData();	//デストラクタ

	HRESULT Init(void);	//初期化処理
	void Uninit(void);	//終了処理

	CreateInfo* GetCreateInfo(const int &nType);	//生成情報の取得

private:
	CreateInfo m_aCreateInfo[BULLET_MAX];	// 生成情報
};

#endif