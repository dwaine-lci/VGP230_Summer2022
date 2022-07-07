#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0     NONE   float   xyzw
// NORMAL                   0   xyz         1     NONE   float   xyz 
// TANGENT                  0   xyzw        2     NONE   float   xyzw
// COLOR                    0   xyzw        3     NONE   float   xyzw
// TEXCOORD                 0   xy          4     NONE   float   xy  
// BLENDINDICES             0   xyzw        5     NONE    uint   x   
// BLENDWEIGHT              0   xyzw        6     NONE   float   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
// TEXCOORD                 1   xyz         3     NONE   float   xyz 
// TEXCOORD                 2   xyz         4     NONE   float   xyz 
// TEXCOORD                 3   xyz         5     NONE   float   xyz 
// TEXCOORD                 4   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xyz         7     NONE   float   xyz 
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb4             0       216  ( FLT, FLT, FLT, FLT)
// c217       cb0             1         1  ( FLT, FLT, FLT, FLT)
// c218       cb2             0         3  ( FLT, FLT, FLT, FLT)
// c221       cb2             4         4  ( FLT, FLT, FLT, FLT)
// c225       cb2            16         2  ( FLT, FLT, FLT, FLT)
// c227       cb2            20         1  ( FLT, FLT, FLT, FLT)
//
//
// Runtime generated constant mappings:
//
// Target Reg                               Constant Description
// ---------- --------------------------------------------------
// c216                            Vertex Shader position offset
//
//
// Level9 shader bytecode:
//
    vs_2_0
    def c228, 3, 1, 0, 0
    dcl_texcoord v0  // vertex<0,1,2,3>
    dcl_texcoord1 v1  // vertex<4,5,6>
    dcl_texcoord2 v2  // vertex<7,8,9,10>
    dcl_texcoord3 v3  // vertex<11,12,13,14>
    dcl_texcoord4 v4  // vertex<15,16>
    dcl_texcoord5 v5  // vertex<17,18,19,20>
    dcl_texcoord6 v6  // vertex<21,22,23,24>

#line 108 "C:\Users\LCI_Vancouver-DWaine\Source\Repos\VGP230_Summer2022\X\External\DirectXTK\src\Shaders\DGSLEffect.fx"
    mul r0.x, v5.x, c228.x
    mova a0.x, r0.x
    mul r0, v6.x, c0[a0.x]  // ::skinning<0,3,6,9>

#line 113
    dp3 oT5.x, v2, r0  // ::main1BonesVc<19>

#line 108
    mul r1, v6.x, c1[a0.x]  // ::skinning<1,4,7,10>
    mul r2, v6.x, c2[a0.x]  // ::skinning<2,5,8,11>

#line 113
    dp3 oT5.y, v2, r1  // ::main1BonesVc<20>
    dp3 oT5.z, v2, r2  // ::main1BonesVc<21>
    dp4 r3.x, v0, r0  // SkinVc::vertex<0>
    dp3 r0.x, v1, r0  // SkinVc::vertex<4>
    dp4 r3.y, v0, r1  // SkinVc::vertex<1>
    dp3 r0.y, v1, r1  // SkinVc::vertex<5>
    dp4 r3.z, v0, r2  // SkinVc::vertex<2>
    dp3 r0.z, v1, r2  // SkinVc::vertex<6>

#line 233
    mov r3.w, v0.w

#line 236
    dp4 oPos.z, r3, c223  // ::main1BonesVc<2>
    mul oT0, v3, c217  // ::main1BonesVc<4,5,6,7>
    mad r1.xyz, v4.xyxw, c228.yyzw, c228.zzyw
    dp3 oT1.x, r1, c225.xyww  // ::main1BonesVc<8>
    dp3 oT1.y, r1, c226.xyww  // ::main1BonesVc<9>
    dp3 oT2.x, r0, c218  // ::main1BonesVc<10>
    dp3 oT2.y, r0, c219  // ::main1BonesVc<11>
    dp3 oT2.z, r0, c220  // ::main1BonesVc<12>

#line 112
    mov oT6.xyz, r0  // ::main1BonesVc<23,24,25>

#line 233
    dp4 r0.x, r3, c218  // ::wp<0>
    dp4 r0.y, r3, c219  // ::wp<1>
    dp4 r0.z, r3, c220  // ::wp<2>

#line 241
    add oT4.xyz, -r0, c227  // ::main1BonesVc<16,17,18>

#line 233
    mov oT3.xyz, r0  // ::main1BonesVc<13,14,15>

#line 236
    dp4 r0.x, r3, c221  // ::result<0>
    dp4 r0.y, r3, c222  // ::result<1>
    dp4 r0.z, r3, c224  // ::result<3>

#line 227
    mad oPos.xy, r0.z, c216, r0  // ::main1BonesVc<0,1>
    mov oPos.w, r0.z  // ::main1BonesVc<3>

#line 113
    mov oT5.w, v2.w  // ::main1BonesVc<22>

// approximately 35 instruction slots used
vs_4_0
dcl_constantbuffer CB0[2], immediateIndexed
dcl_constantbuffer CB2[21], immediateIndexed
dcl_constantbuffer CB4[216], dynamicIndexed
dcl_input v0.xyzw
dcl_input v1.xyz
dcl_input v2.xyzw
dcl_input v3.xyzw
dcl_input v4.xy
dcl_input v5.x
dcl_input v6.x
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_output o2.xy
dcl_output o3.xyz
dcl_output o4.xyz
dcl_output o5.xyz
dcl_output o6.xyzw
dcl_output o7.xyz
dcl_temps 5
imul null, r0.x, v5.x, l(3)
mul r1.xyzw, v6.xxxx, cb4[r0.x + 0].xyzw
dp4 r2.x, v0.xyzw, r1.xyzw
mul r3.xyzw, v6.xxxx, cb4[r0.x + 1].xyzw
mul r0.xyzw, v6.xxxx, cb4[r0.x + 2].xyzw
dp4 r2.y, v0.xyzw, r3.xyzw
dp4 r2.z, v0.xyzw, r0.xyzw
mov r2.w, v0.w
dp4 o0.x, r2.xyzw, cb2[4].xyzw
dp4 o0.y, r2.xyzw, cb2[5].xyzw
dp4 o0.z, r2.xyzw, cb2[6].xyzw
dp4 o0.w, r2.xyzw, cb2[7].xyzw
mul o1.xyzw, v3.xyzw, cb0[1].xyzw
mov r4.xy, v4.xyxx
mov r4.z, l(1.000000)
dp3 o2.x, r4.xyzx, cb2[16].xywx
dp3 o2.y, r4.xyzx, cb2[17].xywx
dp3 r4.x, v1.xyzx, r1.xyzx
dp3 o6.x, v2.xyzx, r1.xyzx
dp3 r4.y, v1.xyzx, r3.xyzx
dp3 o6.y, v2.xyzx, r3.xyzx
dp3 r4.z, v1.xyzx, r0.xyzx
dp3 o6.z, v2.xyzx, r0.xyzx
dp3 o3.x, r4.xyzx, cb2[0].xyzx
dp3 o3.y, r4.xyzx, cb2[1].xyzx
dp3 o3.z, r4.xyzx, cb2[2].xyzx
mov o7.xyz, r4.xyzx
dp4 r0.x, r2.xyzw, cb2[0].xyzw
dp4 r0.y, r2.xyzw, cb2[1].xyzw
dp4 r0.z, r2.xyzw, cb2[2].xyzw
mov o4.xyz, r0.xyzx
add o5.xyz, -r0.xyzx, cb2[20].xyzx
mov o6.w, v2.w
ret 
// Approximately 0 instruction slots used
#endif

const BYTE DGSLEffect_main1BonesVc[] =
{
     68,  88,  66,  67,  25,  78, 
    155, 214, 161, 201,  38, 153, 
     14,  24, 182,  41, 210, 133, 
    128, 149,   1,   0,   0,   0, 
    236,  15,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
     52,   9,   0,   0,   4,  14, 
      0,   0,   0,  15,   0,   0, 
     65, 111, 110,  57, 252,   8, 
      0,   0, 252,   8,   0,   0, 
      0,   2, 254, 255, 140,   8, 
      0,   0, 112,   0,   0,   0, 
      6,   0,  36,   0,   0,   0, 
    108,   0,   0,   0, 108,   0, 
      0,   0,  36,   0,   1,   0, 
    108,   0,   4,   0,   0,   0, 
    216,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      1,   0, 217,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0, 218,   0,   0,   0, 
      0,   0,   2,   0,   4,   0, 
      4,   0, 221,   0,   0,   0, 
      0,   0,   2,   0,  16,   0, 
      2,   0, 225,   0,   0,   0, 
      0,   0,   2,   0,  20,   0, 
      1,   0, 227,   0,   0,   0, 
      0,   0,   0,   0, 216,   0, 
      0,   2, 254, 255, 254, 255, 
    122,   1,  68,  66,  85,  71, 
     40,   0,   0,   0, 188,   5, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 148,   0, 
      0,   0,  43,   0,   0,   0, 
    152,   0,   0,   0,   6,   0, 
      0,   0,  68,   5,   0,   0, 
    240,   1,   0,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92,  76,  67,  73,  95,  86, 
     97, 110,  99, 111, 117, 118, 
    101, 114,  45,  68,  87,  97, 
    105, 110, 101,  92,  83, 111, 
    117, 114,  99, 101,  92,  82, 
    101, 112, 111, 115,  92,  86, 
     71,  80,  50,  51,  48,  95, 
     83, 117, 109, 109, 101, 114, 
     50,  48,  50,  50,  92,  88, 
     92,  69, 120, 116, 101, 114, 
    110,  97, 108,  92,  68, 105, 
    114, 101,  99, 116,  88,  84, 
     75,  92, 115, 114,  99,  92, 
     83, 104,  97, 100, 101, 114, 
    115,  92,  68,  71,  83,  76, 
     69, 102, 102, 101,  99, 116, 
     46, 102, 120,   0,  40,   0, 
      0,   0,   0,   0, 255, 255, 
    240,   5,   0,   0,   0,   0, 
    255, 255,   8,   6,   0,   0, 
      0,   0, 255, 255,  20,   6, 
      0,   0,   0,   0, 255, 255, 
     32,   6,   0,   0,   0,   0, 
    255, 255,  44,   6,   0,   0, 
      0,   0, 255, 255,  56,   6, 
      0,   0,   0,   0, 255, 255, 
     68,   6,   0,   0,   0,   0, 
    255, 255,  80,   6,   0,   0, 
    108,   0,   0,   0,  92,   6, 
      0,   0, 108,   0,   0,   0, 
    108,   6,   0,   0, 108,   0, 
      0,   0, 120,   6,   0,   0, 
    113,   0,   0,   0, 140,   6, 
      0,   0, 108,   0,   0,   0, 
    156,   6,   0,   0, 108,   0, 
      0,   0, 176,   6,   0,   0, 
    113,   0,   0,   0, 196,   6, 
      0,   0, 113,   0,   0,   0, 
    212,   6,   0,   0, 111,   0, 
      0,   0, 228,   6,   0,   0, 
    112,   0,   0,   0, 244,   6, 
      0,   0, 111,   0,   0,   0, 
      4,   7,   0,   0, 112,   0, 
      0,   0,  20,   7,   0,   0, 
    111,   0,   0,   0,  36,   7, 
      0,   0, 112,   0,   0,   0, 
     52,   7,   0,   0, 233,   0, 
      0,   0,  68,   7,   0,   0, 
    236,   0,   0,   0,  80,   7, 
      0,   0, 237,   0,   0,   0, 
     96,   7,   0,   0, 238,   0, 
      0,   0, 112,   7,   0,   0, 
    238,   0,   0,   0, 132,   7, 
      0,   0, 238,   0,   0,   0, 
    148,   7,   0,   0, 239,   0, 
      0,   0, 164,   7,   0,   0, 
    239,   0,   0,   0, 180,   7, 
      0,   0, 239,   0,   0,   0, 
    196,   7,   0,   0, 112,   0, 
      0,   0, 212,   7,   0,   0, 
    233,   0,   0,   0, 224,   7, 
      0,   0, 233,   0,   0,   0, 
    240,   7,   0,   0, 233,   0, 
      0,   0,   0,   8,   0,   0, 
    241,   0,   0,   0,  16,   8, 
      0,   0, 233,   0,   0,   0, 
     32,   8,   0,   0, 236,   0, 
      0,   0,  44,   8,   0,   0, 
    236,   0,   0,   0,  60,   8, 
      0,   0, 236,   0,   0,   0, 
     76,   8,   0,   0, 227,   0, 
      0,   0,  92,   8,   0,   0, 
    227,   0,   0,   0, 112,   8, 
      0,   0, 113,   0,   0,   0, 
    124,   8,   0,   0, 109,  97, 
    105, 110,  49,  66, 111, 110, 
    101, 115,  86,  99,   0, 112, 
    111, 115,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 100, 105, 
    102, 102, 117, 115, 101,   0, 
    117, 118,   0, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 119, 111, 114, 108, 
    100,  78, 111, 114, 109,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   3,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    119, 111, 114, 108, 100,  80, 
    111, 115,   0, 116, 111,  69, 
    121, 101,   0, 116,  97, 110, 
    103, 101, 110, 116,   0, 110, 
    111, 114, 109,  97, 108,   0, 
    171, 171, 253,   1,   0,   0, 
      4,   2,   0,   0,  20,   2, 
      0,   0,   4,   2,   0,   0, 
     28,   2,   0,   0,  32,   2, 
      0,   0,  48,   2,   0,   0, 
     60,   2,   0,   0,  76,   2, 
      0,   0,  60,   2,   0,   0, 
     85,   2,   0,   0,  60,   2, 
      0,   0,  91,   2,   0,   0, 
      4,   2,   0,   0,  99,   2, 
      0,   0,  60,   2,   0,   0, 
      5,   0,   0,   0,   1,   0, 
     26,   0,   1,   0,   8,   0, 
    108,   2,   0,   0,  11,   0, 
      0,   0,  19,   0, 255, 255, 
    255, 255, 255, 255,  14,   0, 
      0,   0, 255, 255,  20,   0, 
    255, 255, 255, 255,  15,   0, 
      0,   0, 255, 255, 255, 255, 
     21,   0, 255, 255,  23,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0, 255, 255,  24,   0, 
      0,   0,   4,   0,   5,   0, 
      6,   0,   7,   0,  26,   0, 
      0,   0,   8,   0, 255, 255, 
    255, 255, 255, 255,  27,   0, 
      0,   0, 255, 255,   9,   0, 
    255, 255, 255, 255,  28,   0, 
      0,   0,  10,   0, 255, 255, 
    255, 255, 255, 255,  29,   0, 
      0,   0, 255, 255,  11,   0, 
    255, 255, 255, 255,  30,   0, 
      0,   0, 255, 255, 255, 255, 
     12,   0, 255, 255,  31,   0, 
      0,   0,  23,   0,  24,   0, 
     25,   0, 255, 255,  35,   0, 
      0,   0,  16,   0,  17,   0, 
     18,   0, 255, 255,  36,   0, 
      0,   0,  13,   0,  14,   0, 
     15,   0, 255, 255,  40,   0, 
      0,   0,   0,   0,   1,   0, 
    255, 255, 255, 255,  41,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   3,   0,  42,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,  22,   0, 114, 101, 
    115, 117, 108, 116,   0, 171, 
      5,   0,   0,   0,   1,   0, 
     26,   0,   1,   0,   8,   0, 
    108,   2,   0,   0,  37,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,  38,   0, 
      0,   0, 255, 255,   1,   0, 
    255, 255, 255, 255,  39,   0, 
      0,   0, 255, 255, 255, 255, 
      3,   0, 255, 255, 115, 107, 
    105, 110, 110, 105, 110, 103, 
      0, 171, 171, 171,   3,   0, 
      3,   0,   4,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
      0,   0,   3,   0,   6,   0, 
      9,   0,  12,   0,   0,   0, 
      1,   0,   4,   0,   7,   0, 
     10,   0,  13,   0,   0,   0, 
      2,   0,   5,   0,   8,   0, 
     11,   0,  83, 107, 105, 110, 
     86,  99,   0, 118, 101, 114, 
    116, 101, 120,   0,  99, 111, 
    108, 111, 114,   0,  98, 111, 
    110, 101,  73, 110, 100, 105, 
     99, 101, 115,   0,   1,   0, 
      2,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  98, 108, 101, 110, 
    100,  87, 101, 105, 103, 104, 
    116, 115,   0, 171, 171, 171, 
    253,   1,   0,   0,   4,   2, 
      0,   0,  99,   2,   0,   0, 
     60,   2,   0,   0,  91,   2, 
      0,   0,   4,   2,   0,   0, 
      6,   4,   0,   0,   4,   2, 
      0,   0,  28,   2,   0,   0, 
     32,   2,   0,   0,  12,   4, 
      0,   0,  24,   4,   0,   0, 
     40,   4,   0,   0,   4,   2, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  25,   0,   1,   0, 
      7,   0,  56,   4,   0,   0, 
     16,   0,   0,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     17,   0,   0,   0,   4,   0, 
    255, 255, 255, 255, 255, 255, 
     18,   0,   0,   0, 255, 255, 
      1,   0, 255, 255, 255, 255, 
     19,   0,   0,   0, 255, 255, 
      5,   0, 255, 255, 255, 255, 
     20,   0,   0,   0, 255, 255, 
    255, 255,   2,   0, 255, 255, 
     21,   0,   0,   0, 255, 255, 
    255, 255,   6,   0, 255, 255, 
      1,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
      2,   0,   0,   0,   4,   0, 
      5,   0,   6,   0, 255, 255, 
      3,   0,   0,   0,   7,   0, 
      8,   0,   9,   0,  10,   0, 
      4,   0,   0,   0,  11,   0, 
     12,   0,  13,   0,  14,   0, 
      5,   0,   0,   0,  15,   0, 
     16,   0, 255, 255, 255, 255, 
      6,   0,   0,   0,  17,   0, 
     18,   0,  19,   0,  20,   0, 
      7,   0,   0,   0,  21,   0, 
     22,   0,  23,   0,  24,   0, 
    119, 112,   0, 171,  32,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,  33,   0, 
      0,   0, 255, 255,   1,   0, 
    255, 255, 255, 255,  34,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0, 255, 255,   0,   0, 
      0,   0, 240,   1,   0,   0, 
    172,   2,   0,   0,  16,   0, 
      0,   0, 188,   2,   0,   0, 
      0,   0,   0,   0, 124,   3, 
      0,   0, 132,   3,   0,   0, 
      3,   0,   0,   0, 148,   3, 
      0,   0,   0,   0,   0,   0, 
    184,   3,   0,   0, 196,   3, 
      0,   0,   3,   0,   0,   0, 
    212,   3,   0,   0, 248,   3, 
      0,   0, 255,   3,   0,   0, 
    112,   4,   0,   0,   6,   0, 
      0,   0, 128,   4,   0,   0, 
    240,   1,   0,   0, 255,   3, 
      0,   0, 112,   4,   0,   0, 
      7,   0,   0,   0, 200,   4, 
      0,   0,   0,   0,   0,   0, 
     28,   5,   0,   0,  60,   2, 
      0,   0,   3,   0,   0,   0, 
     32,   5,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  81,   0,   0,   5, 
    228,   0,  15, 160,   0,   0, 
     64,  64,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
      5,   0,   0, 128,   0,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   1, 128,   1,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   2, 128,   2,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   3, 128,   3,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   4, 128,   4,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   5, 128,   5,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   6, 128,   6,   0, 
     15, 144,   5,   0,   0,   3, 
      0,   0,   1, 128,   5,   0, 
      0, 144, 228,   0,   0, 160, 
     46,   0,   0,   2,   0,   0, 
      1, 176,   0,   0,   0, 128, 
      5,   0,   0,   4,   0,   0, 
     15, 128,   6,   0,   0, 144, 
      0,  32, 228, 160,   0,   0, 
      0, 176,   8,   0,   0,   3, 
      5,   0,   1, 224,   2,   0, 
    228, 144,   0,   0, 228, 128, 
      5,   0,   0,   4,   1,   0, 
     15, 128,   6,   0,   0, 144, 
      1,  32, 228, 160,   0,   0, 
      0, 176,   5,   0,   0,   4, 
      2,   0,  15, 128,   6,   0, 
      0, 144,   2,  32, 228, 160, 
      0,   0,   0, 176,   8,   0, 
      0,   3,   5,   0,   2, 224, 
      2,   0, 228, 144,   1,   0, 
    228, 128,   8,   0,   0,   3, 
      5,   0,   4, 224,   2,   0, 
    228, 144,   2,   0, 228, 128, 
      9,   0,   0,   3,   3,   0, 
      1, 128,   0,   0, 228, 144, 
      0,   0, 228, 128,   8,   0, 
      0,   3,   0,   0,   1, 128, 
      1,   0, 228, 144,   0,   0, 
    228, 128,   9,   0,   0,   3, 
      3,   0,   2, 128,   0,   0, 
    228, 144,   1,   0, 228, 128, 
      8,   0,   0,   3,   0,   0, 
      2, 128,   1,   0, 228, 144, 
      1,   0, 228, 128,   9,   0, 
      0,   3,   3,   0,   4, 128, 
      0,   0, 228, 144,   2,   0, 
    228, 128,   8,   0,   0,   3, 
      0,   0,   4, 128,   1,   0, 
    228, 144,   2,   0, 228, 128, 
      1,   0,   0,   2,   3,   0, 
      8, 128,   0,   0, 255, 144, 
      9,   0,   0,   3,   0,   0, 
      4, 192,   3,   0, 228, 128, 
    223,   0, 228, 160,   5,   0, 
      0,   3,   0,   0,  15, 224, 
      3,   0, 228, 144, 217,   0, 
    228, 160,   4,   0,   0,   4, 
      1,   0,   7, 128,   4,   0, 
    196, 144, 228,   0, 229, 160, 
    228,   0, 218, 160,   8,   0, 
      0,   3,   1,   0,   1, 224, 
      1,   0, 228, 128, 225,   0, 
    244, 160,   8,   0,   0,   3, 
      1,   0,   2, 224,   1,   0, 
    228, 128, 226,   0, 244, 160, 
      8,   0,   0,   3,   2,   0, 
      1, 224,   0,   0, 228, 128, 
    218,   0, 228, 160,   8,   0, 
      0,   3,   2,   0,   2, 224, 
      0,   0, 228, 128, 219,   0, 
    228, 160,   8,   0,   0,   3, 
      2,   0,   4, 224,   0,   0, 
    228, 128, 220,   0, 228, 160, 
      1,   0,   0,   2,   6,   0, 
      7, 224,   0,   0, 228, 128, 
      9,   0,   0,   3,   0,   0, 
      1, 128,   3,   0, 228, 128, 
    218,   0, 228, 160,   9,   0, 
      0,   3,   0,   0,   2, 128, 
      3,   0, 228, 128, 219,   0, 
    228, 160,   9,   0,   0,   3, 
      0,   0,   4, 128,   3,   0, 
    228, 128, 220,   0, 228, 160, 
      2,   0,   0,   3,   4,   0, 
      7, 224,   0,   0, 228, 129, 
    227,   0, 228, 160,   1,   0, 
      0,   2,   3,   0,   7, 224, 
      0,   0, 228, 128,   9,   0, 
      0,   3,   0,   0,   1, 128, 
      3,   0, 228, 128, 221,   0, 
    228, 160,   9,   0,   0,   3, 
      0,   0,   2, 128,   3,   0, 
    228, 128, 222,   0, 228, 160, 
      9,   0,   0,   3,   0,   0, 
      4, 128,   3,   0, 228, 128, 
    224,   0, 228, 160,   4,   0, 
      0,   4,   0,   0,   3, 192, 
      0,   0, 170, 128, 216,   0, 
    228, 160,   0,   0, 228, 128, 
      1,   0,   0,   2,   0,   0, 
      8, 192,   0,   0, 170, 128, 
      1,   0,   0,   2,   5,   0, 
      8, 224,   2,   0, 255, 144, 
    255, 255,   0,   0,  83,  72, 
     68,  82, 200,   4,   0,   0, 
     64,   0,   1,   0,  50,   1, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   2,   0,   0,   0, 
     21,   0,   0,   0,  89,   8, 
      0,   4,  70, 142,  32,   0, 
      4,   0,   0,   0, 216,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   0,   0, 
      0,   0,  95,   0,   0,   3, 
    114,  16,  16,   0,   1,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   2,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   3,   0, 
      0,   0,  95,   0,   0,   3, 
     50,  16,  16,   0,   4,   0, 
      0,   0,  95,   0,   0,   3, 
     18,  16,  16,   0,   5,   0, 
      0,   0,  95,   0,   0,   3, 
     18,  16,  16,   0,   6,   0, 
      0,   0, 103,   0,   0,   4, 
    242,  32,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   3,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   4,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   5,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   6,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   7,   0,   0,   0, 
    104,   0,   0,   2,   5,   0, 
      0,   0,  38,   0,   0,   8, 
      0, 208,   0,   0,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   5,   0, 
      0,   0,   1,  64,   0,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0,   6,  16, 
     16,   0,   6,   0,   0,   0, 
     70, 142,  32,   4,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  17,   0, 
      0,   7,  18,   0,  16,   0, 
      2,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,   6,  16,  16,   0, 
      6,   0,   0,   0,  70, 142, 
     32,   6,   4,   0,   0,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,  10, 242,   0, 
     16,   0,   0,   0,   0,   0, 
      6,  16,  16,   0,   6,   0, 
      0,   0,  70, 142,  32,   6, 
      4,   0,   0,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  17,   0, 
      0,   7,  34,   0,  16,   0, 
      2,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  17,   0,   0,   7, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,  16,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   8, 
     18,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      4,   0,   0,   0,  17,   0, 
      0,   8,  34,  32,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
     17,   0,   0,   8,  66,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   6,   0, 
      0,   0,  17,   0,   0,   8, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      7,   0,   0,   0,  56,   0, 
      0,   8, 242,  32,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   5,  50,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  16,  16,   0,   4,   0, 
      0,   0,  54,   0,   0,   5, 
     66,   0,  16,   0,   4,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  16,   0, 
      0,   8,  18,  32,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     70, 131,  32,   0,   2,   0, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   8,  34,  32, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   4,   0, 
      0,   0,  70, 131,  32,   0, 
      2,   0,   0,   0,  17,   0, 
      0,   0,  16,   0,   0,   7, 
     18,   0,  16,   0,   4,   0, 
      0,   0,  70,  18,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     16,   0,   0,   7,  18,  32, 
     16,   0,   6,   0,   0,   0, 
     70,  18,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  16,   0, 
      0,   7,  34,   0,  16,   0, 
      4,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  16,   0,   0,   7, 
     34,  32,  16,   0,   6,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     16,   0,   0,   7,  66,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  18,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   7,  66,  32,  16,   0, 
      6,   0,   0,   0,  70,  18, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  16,   0,   0,   8, 
     18,  32,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      4,   0,   0,   0,  70, 130, 
     32,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   8,  34,  32,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     70, 130,  32,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
     16,   0,   0,   8,  66,  32, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   4,   0, 
      0,   0,  70, 130,  32,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,  54,   0,   0,   5, 
    114,  32,  16,   0,   7,   0, 
      0,   0,  70,   2,  16,   0, 
      4,   0,   0,   0,  17,   0, 
      0,   8,  18,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
     17,   0,   0,   8,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  17,   0,   0,   8, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,  54,   0, 
      0,   5, 114,  32,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   9, 114,  32, 
     16,   0,   5,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   2,   0, 
      0,   0,  20,   0,   0,   0, 
     54,   0,   0,   5, 130,  32, 
     16,   0,   6,   0,   0,   0, 
     58,  16,  16,   0,   2,   0, 
      0,   0,  62,   0,   0,   1, 
     73,  83,  71,  78, 244,   0, 
      0,   0,   7,   0,   0,   0, 
      8,   0,   0,   0, 176,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,  15,   0,   0, 188,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      7,   7,   0,   0, 195,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     15,  15,   0,   0, 203,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,  15,   0,   0, 209,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      3,   3,   0,   0, 218,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   5,   0,   0,   0, 
     15,   1,   0,   0, 231,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,   1,   0,   0,  83,  86, 
     95,  80, 111, 115, 105, 116, 
    105, 111, 110,   0,  78,  79, 
     82,  77,  65,  76,   0,  84, 
     65,  78,  71,  69,  78,  84, 
      0,  67,  79,  76,  79,  82, 
      0,  84,  69,  88,  67,  79, 
     79,  82,  68,   0,  66,  76, 
     69,  78,  68,  73,  78,  68, 
     73,  67,  69,  83,   0,  66, 
     76,  69,  78,  68,  87,  69, 
     73,  71,  72,  84,   0, 171, 
     79,  83,  71,  78, 228,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0, 200,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0, 212,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,   0,   0,   0, 218,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,  12,   0,   0, 218,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   8,   0,   0, 218,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      7,   8,   0,   0, 218,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
      7,   8,   0,   0, 218,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,   0,   0,   0, 218,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
      7,   8,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171
};