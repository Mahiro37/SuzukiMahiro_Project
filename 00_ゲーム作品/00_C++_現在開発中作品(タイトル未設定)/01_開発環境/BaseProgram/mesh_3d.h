#ifndef _MESH_3D_H_
#define _MESH_3D_H_
//=============================================================================
//
// 3Dメッシュ生成クラスヘッダー [mesh_3d.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "scene_base.h"

//=============================================================================
// メッシュフィールドクラス
//=============================================================================
class CMesh3d : public CSceneBase
{
public:
    //=============================================================================
    // 列挙型
    //=============================================================================
    enum MESH_TYPE
    {
        MESH_TYPE_NONE = -1,    // 初期値
        MESH_TYPE_TUBE_6,       // 6角形の円柱
        MESH_TYPE_PILLAR_6,     // 6角形の円柱
        MESH_TYPE_MAX           // 最大値
    };


    CMesh3d(PRIORITY Priority = PRIORITY_0);    // コンストラクタ
    ~CMesh3d();                                 // デストラクタ

    virtual HRESULT Init() = 0;                 // 初期化処理
    virtual void Update() = 0;                  // 更新処理
    virtual void Draw();                        // 描画処理

    static HRESULT ReadFile();                  // ファイル読み込み

protected:
    // 何角形かを取得する構造体
    struct CYLINDER
    {
        int nNumX;  // 何角形かの値
        int nNumY;  // 何角形かの値
    };

    // 3Dメッシュの構造体
    struct MESH_3D
    {
        CYLINDER CylinderNum;   // 何角形か
        D3DXVECTOR2 size;       // サイズ
    };

    // Set関数
    inline void SetNumVertex(const int &nNumVertex)                 { m_nNumVertex = nNumVertex; }      // 頂点数
    inline void SetNumIndex(const int &nNumIndex)                   { m_nNumIndex = nNumIndex; }        // インデックス数
    inline void SetNumPolygon(const int &nNumPolygon)               { m_nNumPolygon = nNumPolygon; }    // ポリゴン数
    inline void BindIdxBuff(const LPDIRECT3DINDEXBUFFER9 &IdxBuff)  { m_pIdxBuff = IdxBuff; }           // バッファ番号の設定
    inline void BindMtxWorld(const D3DXMATRIX &mtxWorld)            { m_mtxWorld = mtxWorld; }          // マトリクス情報
    inline void SetOneSize(const D3DXVECTOR2 &OneSize)              { m_OneSize = OneSize; }            // 一つのブロックの大きさ
    inline void SetPieceNum(const INT_VERTEX_2D &PieceNum)          { m_PieceNum = PieceNum; }          // ブロックの数
    inline void SetMeshNum(const MESH_TYPE &MeshNum)                { m_MeshNum = MeshNum; }            // メッシュの番号の設定
    void SetCylinderNum(const CYLINDER &CylinderNum, 
        const MESH_TYPE &typeNum)                            { m_Mesh3D[typeNum].CylinderNum = CylinderNum; }    // 何角形か設定する

    // Get関数
    inline int &GetNumVertex()                                  { return m_nNumVertex; }                    // 頂点数の情報
    inline int &GetNumIndex()                                   { return m_nNumIndex; }                     // インデックス数の情報
    inline int &GetNumPolygon()                                 { return m_nNumPolygon; }                   // ポリゴン数の情報
    inline CYLINDER &GetCylinderNum(const MESH_TYPE &typeNum)   { return m_Mesh3D[typeNum].CylinderNum; }   // 何角形かの情報
    inline MESH_TYPE &GetMeshNum()                              { return m_MeshNum; }                       // メッシュの番号
    inline D3DXVECTOR2 &GetOneSize()                            { return m_OneSize; }                       // サイズ
    inline INT_VERTEX_2D &GetPieceNum()                         { return m_PieceNum; }                      // ブロックの数
    inline LPDIRECT3DINDEXBUFFER9 GetIdxBuff()                  { return m_pIdxBuff; }                      // バッファ番号の情報
    inline D3DXMATRIX GetMtxWorld()                             { return m_mtxWorld; }                      // マトリクス情報
    inline static MESH_3D GetMesh3D(const MESH_TYPE &MeshNum)   { return m_Mesh3D[MeshNum]; }               // メッシュの情報

private:
    LPDIRECT3DINDEXBUFFER9 m_pIdxBuff;      // バッファの番号
    D3DXMATRIX m_mtxWorld;                  // ワールドマトリックス
    D3DXVECTOR3 m_move;                     // 移動
    D3DXVECTOR2 m_OneSize;                  // 一つのポリゴンの大きさ
    INT_VERTEX_2D m_PieceNum;               // 1ブロックの数
    MESH_TYPE m_MeshNum;                    // メッシュの番号
    int m_nNumVertex;                       // 総頂点数
    int m_nNumIndex;                        // 総インデックス数
    int m_nNumPolygon;                      // 総ポリゴン数
    static MESH_3D m_Mesh3D[MESH_TYPE_MAX]; // 3Dメッシュの構造体情報
};

#endif