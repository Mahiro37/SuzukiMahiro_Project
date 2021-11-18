//=============================================================================
//
// 芽ブロック [sprout block.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _SPROUT_BLOCK_H_
#define _SPROUT_BLOCK_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "tile block base.h"
//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// 前方宣言
//=============================================================================
class CModel;
//=============================================================================
// クラス定義
//=============================================================================
class CSproutBlock : public CTileBlockBase
{
public:
	CSproutBlock();
	~CSproutBlock();
	static HRESULT			Load(void);
	static void				Unload(void);
	static CSproutBlock*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size);
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
private:
	static CModel::MODELDATA	m_modeldata;	//モデルデータ
};
#endif