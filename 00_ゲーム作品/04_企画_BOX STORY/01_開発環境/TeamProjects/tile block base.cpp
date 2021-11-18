//=============================================================================
//
// タイルブロックベース [tile block base.h]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "tile block base.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CTileBlockBase::CTileBlockBase()
{
	SetObjType(OBJTYPE_BLOCK);
}
//=============================================================================
// デストラクタ
//=============================================================================
CTileBlockBase::~CTileBlockBase()
{
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CTileBlockBase::Init(void)
{
	CBlockBase::Init();

	SetPriority(PRIORITY_OBJECT_TILE);
	GetModel()->SetPriority(PRIORITY_OBJECT_TILE);
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CTileBlockBase::Uninit(void)
{
	CBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CTileBlockBase::Update(void)
{
	CBlockBase::Update();

}

//=============================================================================
// 描画関数
//=============================================================================
void CTileBlockBase::Draw(void)
{
	CBlockBase::Draw();

}
