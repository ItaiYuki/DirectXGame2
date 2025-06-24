struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};
	
struct Material
{
    float32_t4 color;
};

// ConstantBuffer<ç\ë¢ëÃ> ïœêîñº : register(b0);
ConstantBuffer<Material> gMaterial : register(b0);
struct PixselShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main()
{
    PixelShaderOutput output;
    output.color = gMaterial.color;
    return output;
}

//PixelShaderOutput main()
//{
//    PixelShaderOutput output;
//    output.color = float32_t4(1.0, 1.0, 1.0, 1.0);
//    return output;
//}