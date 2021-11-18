xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 159;
 14.39640;-10.38460;-14.39640;,
 8.53970;-12.66350;-16.93210;,
 9.22670;-5.77580;-21.59450;,
 16.93210;-5.16280;-16.93210;,
 0.00000;-13.79770;-18.18360;,
 0.00000;-6.38340;-23.16510;,
 0.00000;2.15540;-24.83370;,
 9.91380;2.18440;-23.16510;,
 18.18360;2.22540;-18.18360;,
 -8.53970;-12.66350;-16.93210;,
 -9.22670;-5.77580;-21.59450;,
 -14.39640;-10.38460;-14.39640;,
 -16.93210;-5.16280;-16.93210;,
 -18.18360;2.22540;-18.18360;,
 -9.91380;2.18440;-23.16510;,
 -9.22670;9.75650;-21.59450;,
 0.00000;10.29750;-23.16510;,
 -16.93210;9.23220;-16.93210;,
 -14.39640;13.74300;-14.39640;,
 -8.53970;15.74110;-16.93210;,
 0.00000;16.72710;-18.18360;,
 9.22670;9.75650;-21.59450;,
 16.93210;9.23220;-16.93210;,
 8.53970;15.74110;-16.93210;,
 14.39640;13.74300;-14.39640;,
 9.22670;19.11540;-9.22670;,
 16.93210;15.74110;-8.53970;,
 0.00000;19.28920;-9.91380;,
 0.00000;19.71180;0.00000;,
 9.91380;19.50420;0.00000;,
 18.18360;16.72710;0.00000;,
 -9.22670;19.11540;-9.22670;,
 -16.93210;15.74110;-8.53970;,
 -18.18360;16.72710;0.00000;,
 -9.91380;19.50420;0.00000;,
 -9.22670;19.11540;9.22670;,
 0.00000;19.28920;9.91380;,
 -16.93210;15.74110;8.53970;,
 -14.39640;13.74300;14.39640;,
 -8.53970;15.74110;16.93210;,
 0.00000;16.72710;18.18360;,
 9.22670;19.11540;9.22670;,
 16.93210;15.74110;8.53970;,
 8.53970;15.74110;16.93210;,
 14.39640;13.74300;14.39640;,
 9.22670;9.75650;21.59450;,
 16.93210;9.23220;16.93210;,
 0.00000;10.29750;23.16510;,
 0.00000;2.15540;24.83370;,
 9.91380;2.18440;23.16510;,
 18.18360;2.22540;18.18360;,
 -9.22670;9.75650;21.59450;,
 -16.93210;9.23220;16.93210;,
 -18.18360;2.22540;18.18360;,
 -9.91380;2.18440;23.16510;,
 -9.22670;-5.77580;21.59450;,
 0.00000;-6.38340;23.16510;,
 -16.93210;-5.16280;16.93210;,
 -14.39640;-10.38460;14.39640;,
 -8.53970;-12.66350;16.93210;,
 0.00000;-13.79770;18.18360;,
 9.22670;-5.77580;21.59450;,
 16.93210;-5.16280;16.93210;,
 8.53970;-12.66350;16.93210;,
 14.39640;-10.38460;14.39640;,
 9.22670;-16.92190;9.22670;,
 16.93210;-12.66350;8.53970;,
 0.00000;-18.36920;9.91380;,
 0.00000;-19.90700;-0.00000;,
 9.91380;-18.36920;-0.00000;,
 18.18360;-13.79770;-0.00000;,
 -9.22670;-16.92190;9.22670;,
 -16.93210;-12.66350;8.53970;,
 -18.18360;-13.79770;0.00000;,
 -9.91380;-18.36920;0.00000;,
 -9.22670;-16.92190;-9.22670;,
 0.00000;-18.36920;-9.91380;,
 -16.93210;-12.66350;-8.53970;,
 -14.39640;-10.38460;-14.39640;,
 -8.53970;-12.66350;-16.93210;,
 0.00000;-13.79770;-18.18360;,
 9.22670;-16.92190;-9.22670;,
 16.93210;-12.66350;-8.53970;,
 8.53970;-12.66350;-16.93210;,
 14.39640;-10.38460;-14.39640;,
 -16.93210;-12.66350;-8.53970;,
 -21.59450;-5.77580;-9.22670;,
 -18.18360;-13.79770;0.00000;,
 -23.16510;-6.38340;0.00000;,
 -24.83370;2.15540;0.00000;,
 -23.16510;2.18440;-9.91380;,
 -16.93210;-12.66350;8.53970;,
 -21.59450;-5.77580;9.22670;,
 -14.39640;-10.38460;14.39640;,
 -16.93210;-5.16280;16.93210;,
 -18.18360;2.22540;18.18360;,
 -23.16510;2.18440;9.91380;,
 -21.59450;9.75650;9.22670;,
 -23.16510;10.29750;0.00000;,
 -16.93210;9.23220;16.93210;,
 -14.39640;13.74300;14.39640;,
 -16.93210;15.74110;8.53970;,
 -18.18360;16.72710;0.00000;,
 -21.59450;9.75650;-9.22670;,
 -16.93210;15.74110;-8.53970;,
 14.39640;-10.38460;14.39640;,
 16.93210;-12.66350;8.53970;,
 21.59450;-5.77580;9.22670;,
 16.93210;-5.16280;16.93210;,
 18.18360;-13.79770;-0.00000;,
 23.16510;-6.38340;-0.00000;,
 24.83370;2.15540;0.00000;,
 23.16510;2.18440;9.91380;,
 18.18360;2.22540;18.18360;,
 16.93210;-12.66350;-8.53970;,
 21.59450;-5.77580;-9.22670;,
 23.16510;2.18440;-9.91380;,
 21.59450;9.75650;-9.22670;,
 23.16510;10.29750;0.00000;,
 16.93210;15.74110;-8.53970;,
 18.18360;16.72710;0.00000;,
 21.59450;9.75650;9.22670;,
 16.93210;9.23220;16.93210;,
 16.93210;15.74110;8.53970;,
 14.39640;13.74300;14.39640;,
 0.00000;20.59870;4.44520;,
 4.44520;20.59870;0.00000;,
 4.44520;19.90360;0.00000;,
 0.00000;19.90360;4.44520;,
 0.00000;20.59870;-4.44520;,
 0.00000;19.90360;-4.44520;,
 -4.44520;20.59870;0.00000;,
 -4.44520;19.90360;0.00000;,
 0.00000;20.59870;4.44520;,
 0.00000;19.90360;4.44520;,
 0.00000;20.59870;4.44520;,
 -4.44520;20.59870;0.00000;,
 4.44520;20.59870;0.00000;,
 0.00000;19.90360;4.44520;,
 4.44520;19.90360;0.00000;,
 0.00000;19.90360;-4.44520;,
 -4.44520;19.90360;0.00000;,
 3.42260;19.74190;4.47490;,
 4.47490;19.74190;-3.42260;,
 4.47490;19.68380;-3.42260;,
 3.42260;19.68380;4.47490;,
 -3.42260;19.74190;-4.47490;,
 -3.42260;19.68380;-4.47490;,
 -4.47490;19.74190;3.42260;,
 -4.47490;19.68380;3.42260;,
 3.42260;19.74190;4.47490;,
 3.42260;19.68380;4.47490;,
 3.42260;19.74190;4.47490;,
 -4.47490;19.74190;3.42260;,
 4.47490;19.74190;-3.42260;,
 3.42260;19.68380;4.47490;,
 4.47490;19.68380;-3.42260;,
 -3.42260;19.68380;-4.47490;,
 -4.47490;19.68380;3.42260;;
 
 108;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;2,5,6,7;,
 4;3,2,7,8;,
 4;4,9,10,5;,
 4;9,11,12,10;,
 4;10,12,13,14;,
 4;5,10,14,6;,
 4;6,14,15,16;,
 4;14,13,17,15;,
 4;15,17,18,19;,
 4;16,15,19,20;,
 4;8,7,21,22;,
 4;7,6,16,21;,
 4;21,16,20,23;,
 4;22,21,23,24;,
 4;24,23,25,26;,
 4;23,20,27,25;,
 4;25,27,28,29;,
 4;26,25,29,30;,
 4;20,19,31,27;,
 4;19,18,32,31;,
 4;31,32,33,34;,
 4;27,31,34,28;,
 4;28,34,35,36;,
 4;34,33,37,35;,
 4;35,37,38,39;,
 4;36,35,39,40;,
 4;30,29,41,42;,
 4;29,28,36,41;,
 4;41,36,40,43;,
 4;42,41,43,44;,
 4;44,43,45,46;,
 4;43,40,47,45;,
 4;45,47,48,49;,
 4;46,45,49,50;,
 4;40,39,51,47;,
 4;39,38,52,51;,
 4;51,52,53,54;,
 4;47,51,54,48;,
 4;48,54,55,56;,
 4;54,53,57,55;,
 4;55,57,58,59;,
 4;56,55,59,60;,
 4;50,49,61,62;,
 4;49,48,56,61;,
 4;61,56,60,63;,
 4;62,61,63,64;,
 4;64,63,65,66;,
 4;63,60,67,65;,
 4;65,67,68,69;,
 4;66,65,69,70;,
 4;60,59,71,67;,
 4;59,58,72,71;,
 4;71,72,73,74;,
 4;67,71,74,68;,
 4;68,74,75,76;,
 4;74,73,77,75;,
 4;75,77,78,79;,
 4;76,75,79,80;,
 4;70,69,81,82;,
 4;69,68,76,81;,
 4;81,76,80,83;,
 4;82,81,83,84;,
 4;11,85,86,12;,
 4;85,87,88,86;,
 4;86,88,89,90;,
 4;12,86,90,13;,
 4;87,91,92,88;,
 4;91,93,94,92;,
 4;92,94,95,96;,
 4;88,92,96,89;,
 4;89,96,97,98;,
 4;96,95,99,97;,
 4;97,99,100,101;,
 4;98,97,101,102;,
 4;13,90,103,17;,
 4;90,89,98,103;,
 4;103,98,102,104;,
 4;17,103,104,18;,
 4;105,106,107,108;,
 4;106,109,110,107;,
 4;107,110,111,112;,
 4;108,107,112,113;,
 4;109,114,115,110;,
 4;114,0,3,115;,
 4;115,3,8,116;,
 4;110,115,116,111;,
 4;111,116,117,118;,
 4;116,8,22,117;,
 4;117,22,24,119;,
 4;118,117,119,120;,
 4;113,112,121,122;,
 4;112,111,118,121;,
 4;121,118,120,123;,
 4;122,121,123,124;,
 4;125,126,127,128;,
 4;126,129,130,127;,
 4;129,131,132,130;,
 4;131,133,134,132;,
 4;135,136,129,137;,
 4;138,139,140,141;,
 4;142,143,144,145;,
 4;143,146,147,144;,
 4;146,148,149,147;,
 4;148,150,151,149;,
 4;152,153,146,154;,
 4;155,156,157,158;;
 
 MeshMaterialList {
  3;
  108;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.384000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.088000;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.008000;0.344000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  107;
  0.556421;-0.617083;-0.556421;,
  -0.556421;-0.617083;-0.556421;,
  0.521449;0.675412;-0.521449;,
  -0.521449;0.675412;-0.521449;,
  0.521449;0.675412;0.521449;,
  -0.521449;0.675412;0.521449;,
  0.556421;-0.617083;0.556421;,
  -0.556421;-0.617083;0.556421;,
  0.593771;0.804634;0.000000;,
  -0.707095;0.005740;0.707095;,
  0.000000;-0.737942;0.674864;,
  0.707095;0.005740;0.707095;,
  -0.674864;-0.737942;0.000000;,
  0.674864;-0.737942;-0.000000;,
  0.000000;-0.737942;-0.674864;,
  -0.707095;0.005740;-0.707095;,
  0.000000;0.808471;-0.588536;,
  0.707095;0.005740;-0.707095;,
  -0.593771;0.804634;0.000000;,
  0.000000;0.808471;0.588536;,
  0.000000;0.004878;-0.999988;,
  0.000000;1.000000;0.000000;,
  0.000000;0.004878;0.999988;,
  0.000000;-1.000000;-0.000000;,
  -0.999988;0.004878;0.000000;,
  0.999988;0.004878;0.000000;,
  0.639245;0.427472;0.639245;,
  -0.639245;0.427472;0.639245;,
  -0.353602;0.005286;0.935381;,
  -0.650708;-0.391353;0.650708;,
  -0.338802;-0.695868;0.633230;,
  0.000000;-0.389914;0.920851;,
  0.338802;-0.695868;0.633230;,
  0.650708;-0.391353;0.650708;,
  0.000000;-0.944168;0.329464;,
  0.329464;-0.944168;-0.000000;,
  0.633230;-0.695868;0.338802;,
  -0.633230;-0.695868;0.338802;,
  -0.329464;-0.944168;0.000000;,
  -0.633230;-0.695868;-0.338802;,
  0.000000;-0.944168;-0.329464;,
  0.633230;-0.695868;-0.338802;,
  -0.920851;-0.389914;0.000000;,
  -0.935381;0.005286;-0.353602;,
  -0.935381;0.005286;0.353602;,
  -0.905065;0.425274;-0.000000;,
  0.920851;-0.389914;-0.000000;,
  0.935381;0.005286;0.353602;,
  0.935381;0.005286;-0.353602;,
  0.905065;0.425274;0.000000;,
  0.338802;-0.695868;-0.633230;,
  0.000000;-0.389914;-0.920851;,
  0.353602;0.005286;-0.935381;,
  0.650708;-0.391353;-0.650708;,
  -0.338802;-0.695868;-0.633230;,
  -0.650708;-0.391353;-0.650708;,
  -0.353602;0.005286;-0.935381;,
  -0.639245;0.427472;-0.639245;,
  -0.299820;0.763856;-0.571517;,
  0.000000;0.425274;-0.905065;,
  0.299820;0.763856;-0.571517;,
  0.639245;0.427472;-0.639245;,
  0.000000;0.979946;-0.199263;,
  0.194715;0.980860;0.000000;,
  0.573587;0.761273;-0.302426;,
  -0.573587;0.761273;-0.302426;,
  -0.194715;0.980860;0.000000;,
  -0.573587;0.761273;0.302426;,
  -0.299820;0.763856;0.571517;,
  0.000000;0.979946;0.199263;,
  0.299820;0.763856;0.571517;,
  0.573587;0.761273;0.302426;,
  -0.000000;0.425274;0.905065;,
  0.353602;0.005286;0.935381;,
  0.347833;-0.389886;-0.852644;,
  -0.347833;-0.389886;-0.852644;,
  -0.340995;0.425556;-0.838227;,
  0.340995;0.425556;-0.838227;,
  0.231982;0.943231;-0.237695;,
  -0.231982;0.943231;-0.237695;,
  -0.231982;0.943231;0.237695;,
  0.231982;0.943231;0.237695;,
  0.340995;0.425556;0.838227;,
  -0.340995;0.425556;0.838227;,
  -0.347833;-0.389886;0.852644;,
  0.347833;-0.389886;0.852644;,
  0.331199;-0.883524;0.331199;,
  -0.331199;-0.883524;0.331199;,
  -0.331199;-0.883524;-0.331199;,
  0.331199;-0.883524;-0.331199;,
  -0.852644;-0.389886;-0.347833;,
  -0.852644;-0.389886;0.347833;,
  -0.838227;0.425556;0.340995;,
  -0.838227;0.425556;-0.340995;,
  0.852644;-0.389886;0.347833;,
  0.852644;-0.389886;-0.347833;,
  0.838227;0.425556;-0.340995;,
  0.838227;0.425556;0.340995;,
  -0.707107;0.000000;-0.707107;,
  -0.707107;0.000000;0.707107;,
  0.707107;0.000000;0.707107;,
  -0.991239;0.000000;-0.132077;,
  -0.132077;0.000000;0.991239;,
  0.991239;0.000000;0.132077;,
  0.707107;0.000000;-0.707107;,
  0.000000;1.000000;0.000000;,
  0.132077;0.000000;-0.991239;;
  108;
  4;0,50,74,53;,
  4;50,14,51,74;,
  4;74,51,20,52;,
  4;53,74,52,17;,
  4;14,54,75,51;,
  4;54,1,55,75;,
  4;75,55,15,56;,
  4;51,75,56,20;,
  4;20,56,76,59;,
  4;56,15,57,76;,
  4;76,57,3,58;,
  4;59,76,58,16;,
  4;17,52,77,61;,
  4;52,20,59,77;,
  4;77,59,16,60;,
  4;61,77,60,2;,
  4;2,60,78,64;,
  4;60,16,62,78;,
  4;78,62,21,63;,
  4;64,78,63,8;,
  4;16,58,79,62;,
  4;58,3,65,79;,
  4;79,65,18,66;,
  4;62,79,66,21;,
  4;21,66,80,69;,
  4;66,18,67,80;,
  4;80,67,5,68;,
  4;69,80,68,19;,
  4;8,63,81,71;,
  4;63,21,69,81;,
  4;81,69,19,70;,
  4;71,81,70,4;,
  4;4,70,82,26;,
  4;70,19,72,82;,
  4;82,72,22,73;,
  4;26,82,73,11;,
  4;19,68,83,72;,
  4;68,5,27,83;,
  4;83,27,9,28;,
  4;72,83,28,22;,
  4;22,28,84,31;,
  4;28,9,29,84;,
  4;84,29,7,30;,
  4;31,84,30,10;,
  4;11,73,85,33;,
  4;73,22,31,85;,
  4;85,31,10,32;,
  4;33,85,32,6;,
  4;6,32,86,36;,
  4;32,10,34,86;,
  4;86,34,23,35;,
  4;36,86,35,13;,
  4;10,30,87,34;,
  4;30,7,37,87;,
  4;87,37,12,38;,
  4;34,87,38,23;,
  4;23,38,88,40;,
  4;38,12,39,88;,
  4;88,39,1,54;,
  4;40,88,54,14;,
  4;13,35,89,41;,
  4;35,23,40,89;,
  4;89,40,14,50;,
  4;41,89,50,0;,
  4;1,39,90,55;,
  4;39,12,42,90;,
  4;90,42,24,43;,
  4;55,90,43,15;,
  4;12,37,91,42;,
  4;37,7,29,91;,
  4;91,29,9,44;,
  4;42,91,44,24;,
  4;24,44,92,45;,
  4;44,9,27,92;,
  4;92,27,5,67;,
  4;45,92,67,18;,
  4;15,43,93,57;,
  4;43,24,45,93;,
  4;93,45,18,65;,
  4;57,93,65,3;,
  4;6,36,94,33;,
  4;36,13,46,94;,
  4;94,46,25,47;,
  4;33,94,47,11;,
  4;13,41,95,46;,
  4;41,0,53,95;,
  4;95,53,17,48;,
  4;46,95,48,25;,
  4;25,48,96,49;,
  4;48,17,61,96;,
  4;96,61,2,64;,
  4;49,96,64,8;,
  4;11,47,97,26;,
  4;47,25,49,97;,
  4;97,49,8,71;,
  4;26,97,71,4;,
  4;98,98,98,98;,
  4;99,99,99,99;,
  4;100,100,100,100;,
  4;104,104,104,104;,
  4;23,23,23,23;,
  4;105,105,105,105;,
  4;101,101,101,101;,
  4;102,102,102,102;,
  4;103,103,103,103;,
  4;106,106,106,106;,
  4;23,23,23,23;,
  4;105,105,105,105;;
 }
 MeshTextureCoords {
  159;
  0.375000;1.000000;,
  0.437500;1.000000;,
  0.437500;0.937500;,
  0.375000;0.937500;,
  0.500000;1.000000;,
  0.500000;0.937500;,
  0.500000;0.875000;,
  0.437500;0.875000;,
  0.375000;0.875000;,
  0.562500;1.000000;,
  0.562500;0.937500;,
  0.625000;1.000000;,
  0.625000;0.937500;,
  0.625000;0.875000;,
  0.562500;0.875000;,
  0.562500;0.812500;,
  0.500000;0.812500;,
  0.625000;0.812500;,
  0.625000;0.750000;,
  0.562500;0.750000;,
  0.500000;0.750000;,
  0.437500;0.812500;,
  0.375000;0.812500;,
  0.437500;0.750000;,
  0.375000;0.750000;,
  0.437500;0.687500;,
  0.375000;0.687500;,
  0.500000;0.687500;,
  0.500000;0.625000;,
  0.437500;0.625000;,
  0.375000;0.625000;,
  0.562500;0.687500;,
  0.625000;0.687500;,
  0.625000;0.625000;,
  0.562500;0.625000;,
  0.562500;0.562500;,
  0.500000;0.562500;,
  0.625000;0.562500;,
  0.625000;0.500000;,
  0.562500;0.500000;,
  0.500000;0.500000;,
  0.437500;0.562500;,
  0.375000;0.562500;,
  0.437500;0.500000;,
  0.375000;0.500000;,
  0.437500;0.437500;,
  0.375000;0.437500;,
  0.500000;0.437500;,
  0.500000;0.375000;,
  0.437500;0.375000;,
  0.375000;0.375000;,
  0.562500;0.437500;,
  0.625000;0.437500;,
  0.625000;0.375000;,
  0.562500;0.375000;,
  0.562500;0.312500;,
  0.500000;0.312500;,
  0.625000;0.312500;,
  0.625000;0.250000;,
  0.562500;0.250000;,
  0.500000;0.250000;,
  0.437500;0.312500;,
  0.375000;0.312500;,
  0.437500;0.250000;,
  0.375000;0.250000;,
  0.437500;0.187500;,
  0.375000;0.187500;,
  0.500000;0.187500;,
  0.500000;0.125000;,
  0.437500;0.125000;,
  0.375000;0.125000;,
  0.562500;0.187500;,
  0.625000;0.187500;,
  0.625000;0.125000;,
  0.562500;0.125000;,
  0.562500;0.062500;,
  0.500000;0.062500;,
  0.625000;0.062500;,
  0.625000;0.000000;,
  0.562500;0.000000;,
  0.500000;0.000000;,
  0.437500;0.062500;,
  0.375000;0.062500;,
  0.437500;0.000000;,
  0.375000;0.000000;,
  0.687500;1.000000;,
  0.687500;0.937500;,
  0.750000;1.000000;,
  0.750000;0.937500;,
  0.750000;0.875000;,
  0.687500;0.875000;,
  0.812500;1.000000;,
  0.812500;0.937500;,
  0.875000;1.000000;,
  0.875000;0.937500;,
  0.875000;0.875000;,
  0.812500;0.875000;,
  0.812500;0.812500;,
  0.750000;0.812500;,
  0.875000;0.812500;,
  0.875000;0.750000;,
  0.812500;0.750000;,
  0.750000;0.750000;,
  0.687500;0.812500;,
  0.687500;0.750000;,
  0.125000;1.000000;,
  0.187500;1.000000;,
  0.187500;0.937500;,
  0.125000;0.937500;,
  0.250000;1.000000;,
  0.250000;0.937500;,
  0.250000;0.875000;,
  0.187500;0.875000;,
  0.125000;0.875000;,
  0.312500;1.000000;,
  0.312500;0.937500;,
  0.312500;0.875000;,
  0.312500;0.812500;,
  0.250000;0.812500;,
  0.312500;0.750000;,
  0.250000;0.750000;,
  0.187500;0.812500;,
  0.125000;0.812500;,
  0.187500;0.750000;,
  0.125000;0.750000;,
  0.375000;0.687500;,
  0.437500;0.687500;,
  0.437500;0.311560;,
  0.375000;0.311560;,
  0.500000;0.687500;,
  0.500000;0.311560;,
  0.562500;0.687500;,
  0.562500;0.311560;,
  0.625000;0.687500;,
  0.625000;0.311560;,
  0.500000;1.000000;,
  0.656250;0.843750;,
  0.343750;0.843750;,
  0.500000;0.000000;,
  0.343750;0.156250;,
  0.500000;0.312500;,
  0.656250;0.156250;,
  0.375000;0.687500;,
  0.437500;0.687500;,
  0.437500;0.311560;,
  0.375000;0.311560;,
  0.500000;0.687500;,
  0.500000;0.311560;,
  0.562500;0.687500;,
  0.562500;0.311560;,
  0.625000;0.687500;,
  0.625000;0.311560;,
  0.500000;1.000000;,
  0.656250;0.843750;,
  0.343750;0.843750;,
  0.500000;0.000000;,
  0.343750;0.156250;,
  0.500000;0.312500;,
  0.656250;0.156250;;
 }
}
