//=============================================================================
//
// 水面マスクのシェーダ [Mask.fx]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// グローバル変数宣言
//=============================================================================
float4x4 m_WVP;

//=============================================================================
// 構造体
//=============================================================================
struct VS_OUTPUT
{
	float4 Pos : POSITION;
};

//=============================================================================
// 頂点シェーダ
//=============================================================================
VS_OUTPUT VS(float3 Pos : POSITION, float3 Tangent : TANGENT0, 
	float3 Binormal : BINORMAL0, float3 Normal : NORMAL, float2 Tex : TEXCOORD0)
{
	// 変数宣言
	VS_OUTPUT Out;
	Out.Pos = mul(float4(Pos, 1.0f), m_WVP);	// ワールド変換

	return Out;
}

//=============================================================================
// ピクセルシェーダ
//=============================================================================
float4 PS(VS_OUTPUT In) : COLOR0
{
	return 1.0f;
}

//=============================================================================
// テクニック
//=============================================================================
technique TShader
{
	pass P0
	{
		VertexShader = compile vs_1_1 VS();
		PixelShader  = compile ps_2_0 PS();
	}
}