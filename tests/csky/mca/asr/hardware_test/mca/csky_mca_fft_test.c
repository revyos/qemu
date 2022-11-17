#include "hardware_test.h"
#include "csky_mca.h"
#include "csky_mca_test_helper.h"
#include "fft_fxp.h"

// Sample input data
static const fxp32_t SAMPLE_INPUT_DATA[] TEST_DATA_ATTR = {
	0x005e00bc, 0x67eacfd5, 0x7541ea83, 0x47798ef3, 0x4f8b9f17, 0x32d765ae, 0x6f5ddebb, 0x3bba7774,
	0x714be297, 0x5f4fbe9f, 0x0d0b1a16, 0x70b1e163, 0x429f853f, 0x4be097c1, 0x11ec23d8, 0x3d8c7b18,
	0x17d22fa4, 0x2e3a5c74, 0x05470a8e, 0x5387a70f, 0x47ff8fff, 0x009b0136, 0x39ab7356, 0x37026e04,
	0x11d423a8, 0x638ac715, 0x77d6efad, 0x4ed79daf, 0x3d957b2a, 0x47c88f91, 0x50d6a1ad, 0x7deafbd5,
	0x206440c8, 0x7484e909, 0x5b6eb6dd, 0x7b02f605, 0x64bfc97f, 0x3dce7b9c, 0x60bbc177, 0x5ad7b5af,
	0x3c4a7894, 0x7f4efe9d, 0x3c17782e, 0x006c00d8, 0x5ecfbd9f, 0x2f365e6c, 0x723ee47d, 0x679ecf3d,
	0x7a83f507, 0x1d753aea, 0x43b08761, 0x7dfdfbfb, 0x798bf317, 0x332e665c, 0x3e567cac, 0x7ddcfbb9,
	0x40be817d, 0x46688cd1, 0x126724ce, 0x7fa4ff49, 0x4bad975b, 0x5607ac0f, 0x2e8d5d1a, 0x356e6adc,
	0x49e093c1, 0x41fb83f7, 0x6744ce89, 0x04d009a0, 0x216342c6, 0x53b7a76f, 0x2d835b06, 0x72f6e5ed,
	0x7a82f505, 0x2ae455c8, 0x189f313e, 0x16f52dea, 0x38d071a0, 0x6257c4af, 0x476c8ed9, 0x065d0cba,
	0x056e0adc, 0x01410282, 0x5ca5b94b, 0x700de01b, 0x4e899d13, 0x0ca6194c, 0x1a8e351c, 0x594cb299,
	0x6025c04b, 0x4d119a23, 0x61d7c3af, 0x3115622a, 0x7a19f433, 0x1c85390a, 0x17c42f88, 0x2db15b62,
	0x075b0eb6, 0x50b6a16d, 0x378b6f16, 0x288c5118, 0x5a7eb4fd, 0x15792af2, 0x12fe25fc, 0x6c41d883,
	0x137926f2, 0x4b7a96f5, 0x06690cd2, 0x28f751ee, 0x12aa2554, 0x3f2d7e5a, 0x23be477c, 0x02f005e0,
	0x1d1b3a36, 0x4c07980f, 0x18ef31de, 0x6f5fdebf, 0x16032c06, 0x3fed7fda, 0x559cab39, 0x537aa6f5,
	0x7190e321, 0x12ed25da, 0x33ee67dc, 0x19d133a2, 0x44e389c7, 0x472c8e59, 0x28c35186, 0x31de63bc,
	0x175d2eba, 0x051f0a3e, 0x3f0b7e16, 0x2ddd5bba, 0x5919b233, 0x47fe8ffd, 0x6271c4e3, 0x72dee5bd,
	0x22b94572, 0x2e765cec, 0x3d3f7a7e, 0x2f185e30, 0x226644cc, 0x439f873f, 0x2d7b5af6, 0x0a801500,
	0x5a12b425, 0x542da85b, 0x15562aac, 0x459a8b35, 0x13002600, 0x23ea47d4, 0x0ac81590, 0x3a8f751e,
	0x2a87550e, 0x17642ec8, 0x2a7454e8, 0x7481e903, 0x1c133826, 0x25e24bc4, 0x11d123a2, 0x511ba237,
	0x6c6cd8d9, 0x279d4f3a, 0x448b8917, 0x606cc0d9, 0x5a3bb477, 0x542da85b, 0x0127024e, 0x76f5edeb,
	0x77caef95, 0x05420a84, 0x48e791cf, 0x26004c00, 0x120b2416, 0x11942328, 0x1eed3dda, 0x0e341c68,
	0x08dc11b8, 0x541da83b, 0x42a28545, 0x406780cf, 0x7c89f913, 0x3385670a, 0x6959d2b3, 0x20b34166,
	0x7492e925, 0x3dde7bbc, 0x3b307660, 0x7fccff99, 0x63afc75f, 0x2c915922, 0x17372e6e, 0x5e90bd21,
	0x2d125a24, 0x6498c931, 0x62d5c5ab, 0x0fe01fc0, 0x0eec1dd8, 0x46ee8ddd, 0x6867d0cf, 0x2caf595e,
	0x16322c64, 0x6544ca89, 0x09291252, 0x0e581cb0, 0x7fa1ff43, 0x6ef6dded, 0x465a8cb5, 0x4335866b,
	0x2a005400, 0x6a3dd47b, 0x659bcb37, 0x316d62da, 0x7da5fb4b, 0x0da61b4c, 0x34996932, 0x5c0db81b,
	0x6d3ada75, 0x4dc39b87, 0x2feb5fd6, 0x7e5bfcb7, 0x73c1e783, 0x7320e641, 0x113e227c, 0x7167e2cf,
	0x33d667ac, 0x4c7898f1, 0x08af115e, 0x0fe21fc4, 0x1c343868, 0x5129a253, 0x25784af0, 0x0c331866,
	0x357b6af6, 0x47e68fcd, 0x31cf639e, 0x6cc8d991, 0x7d31fa63, 0x45ac8b59, 0x060b0c16, 0x22aa4554,
	0x3f963f2c, 0xfcec65d9, 0x019d929b, 0x00b13432, 0x02725dd5, 0x00ca00fa, 0xff5b525d, 0xfca59400,
	0x0001bff8, 0xfe44d26f, 0xffe48d79, 0x005b21fa, 0xff486163, 0xff4263ce, 0x01306bdc, 0x015cd00a,
	0x0163b85d, 0x0195e8ca, 0xffcc49c4, 0x0245e3fe, 0xff23f889, 0x00658498, 0x0100ea06, 0xff799896,
	0x02f1978c, 0x0092a82d, 0xffe63c1c, 0xff4b8e71, 0x012abfde, 0xff71def2, 0x00e06ae8, 0x00378775,
	0x01a0c20a, 0x00d7cb58, 0x02be2294, 0xfe9c90a9, 0x007b986d, 0x010b28f4, 0x020a5bb6, 0xffeb631c,
	0xff767e4d, 0xff669e14, 0xff061d1b, 0x02361a1d, 0x007091db, 0x000ebab2, 0xff266268, 0xfe3c2966,
	0xfe9f80c4, 0x0088562d, 0xfe910e47, 0x00f4f551, 0xff4ae0cd, 0xffac4570, 0xfd5d12ab, 0x00d4e7cc,
	0x00a2bbb9, 0xffafc041, 0xfefe79c3, 0x008d41d4, 0x0023e57e, 0x005a1827, 0x00196112, 0xfe9877bf,
	0xfe250a3b, 0xfef7ceed, 0xff1b43f3, 0xff9c81fd, 0x0160b512, 0x011c33cc, 0x012f25d9, 0x00e01fb3,
	0xfcd80538, 0xff9d5f3b, 0xffdd1b49, 0xfee62c86, 0xffaea975, 0x0012a4d0, 0xfed6318c, 0x01adbdca,
	0x00dbcc2b, 0xfdbc1003, 0xffca5198, 0x0170f792, 0x003f2dae, 0xfef214bf, 0x00f5ccb2, 0xfec26fec,
	0x007c880f, 0xff25e846, 0x001724e8, 0xfff6be9b, 0x018a8872, 0xffc34f49, 0xff56e122, 0xffee2427,
	0xfed7940d, 0x0098b31e, 0xffd04e89, 0x003a9004, 0x0054282e, 0xff657885, 0x007df5bf, 0xfeffc123,
	0x015788b5, 0x0034f43e, 0x00555de8, 0x00a5dad3, 0xffa00057, 0x00b0e413, 0xff7ec8be, 0xff1e5a2f,
	0x00816a48, 0x00b3d87f, 0x0237fa6f, 0xff8e6f65, 0x00e733eb, 0x001742d9, 0xfea60d6a, 0xffb04be2,
	0xffad7413, 0x0011390d, 0x01846327, 0xfe579ca8, 0x013bab92, 0x017146e4, 0xfff04121, 0x01164949,
	0xff39f221, 0x007be265, 0xfea66454, 0xffd35be6, 0x011fdef2, 0xff7e4885, 0xff4eced6, 0x00f58009,
	0xff46086e, 0xfefb309f, 0xffe6ee3b, 0x004dde46, 0xff0ba6fe, 0xfe92fd71, 0xff44ae3f, 0xffd3faf4,
	0x00c17682, 0x01b5384d, 0x005f0b68, 0x016aa331, 0x00bb6411, 0x009e1b4a, 0xfe84b7c6, 0xff4dffc0,
	0x0025c712, 0x00a1fdf7, 0xff9d945a, 0x0149d43e, 0x00cce077, 0xff2b2506, 0x00911cca, 0x00985beb,
	0x012d17f4, 0xff473c61, 0x00062ccf, 0xfe47bdc3, 0xfe7c8bd9, 0x0067132c, 0xfe93599f, 0xfd9792d5,
	0xfea0e7f0, 0x01a00de6, 0x00c3916d, 0x0058c4d6, 0x011223a7, 0xfe97d5a6, 0x0139ab8e, 0xffe48206,
	0x00ad2882, 0xfe390aff, 0x007426fd, 0xff1d802c, 0x003aea9c, 0x015efe04, 0xfdcfecf8, 0x001ef242,
	0xff625de2, 0x01670766, 0xfefe00d8, 0x00249618, 0xffcd0a68, 0xfd492ad4, 0x01027e5b, 0xff976780,
	0xfe28957e, 0xfe453f2f, 0xff5f9518, 0x01acfad4, 0xffe031a4, 0x0329e487, 0x00b61f7f, 0xff2511d4,
	0x01b5103d, 0x00b9cc5f, 0xfef63476, 0xfe1f5521, 0xfff1d13b, 0xffe6eb95, 0x0177f3d7, 0xfed75eb3,
	0xff6c36bb, 0x0046c807, 0xff9fa289, 0xff65367a, 0xffee450f, 0x007010e7, 0x0025ade7, 0x00260959,
	0xfdd9cf15, 0xffd16d37, 0x004549aa, 0x02230f92, 0xfef375eb, 0xfebc2d5b, 0x011769f0, 0x023c6d22,
	0xfebabd29, 0x0042a58a, 0x0015476c, 0xfe26dd7c, 0xfed2d40f, 0x0004f170, 0xfe931bda, 0x00ced536,
	0xff5beaa8, 0xffcc6ac2, 0x01480fef, 0x021e8be6, 0xfda95ef2, 0x00036619, 0x02a1daaa, 0xffb57205,
	0xff06ad50, 0xfea7748d, 0x01895a12, 0x00a0b759, 0x005caa56, 0x0031e7a7, 0x000e0a08, 0x0000bac0,
	0xfdfd9b9b, 0xff850f9f, 0x006c90ee, 0x00df4114, 0xff774696, 0xfec6b73c, 0x00a09eba, 0x025d7816,
	0x0086b50d, 0x030c3118, 0xff51b592, 0xff8e2a8d, 0x00257303, 0x0122fba8, 0xfe78f18b, 0xff96ff54,
	0x0075ffe1, 0x00ed38bc, 0xfed3cff3, 0xff1f4dc9, 0xffaff11b, 0x00fc8c1b, 0x0103f9ad, 0xffbc1747,
	0xfe7502d9, 0xffbbb2e9, 0x00e9ff4a, 0x0098df34, 0x0080af8e, 0x0023dacf, 0xff11a5e9, 0x0022e91d,
	0xfee7c235, 0xff42b59d, 0x004db5c0, 0xfe7490b1, 0xff1f5dc0, 0xfebe74ef, 0xff5ed759, 0xfd8eef00,
	0xfe6e9054, 0x010fbf71, 0x003817c3, 0x00490c30, 0xfd06ecb4, 0xff90ddf7, 0x0016c1b1, 0x01394569,
	0x000bf202, 0x00bed728, 0xfe83264d, 0xffc15129, 0x02772968, 0xff482784, 0xfe1c06e3, 0x00acd25b,
	0xfe7eefb3, 0x005035d9, 0x0047b2d2, 0xff673ddf, 0xff21fb01, 0x0015d7b3, 0xfe96fe3e, 0x02a2b362,
	0xffe5bf73, 0xffb82402, 0xfee078fa, 0xff64d38c, 0xff266525, 0x022472e5, 0x0094f89c, 0xff7253c8,
	0xff342c07, 0xff5966a5, 0x00e89f03, 0xff366825, 0xff6ee172, 0x00d7ecaa, 0x00fc37b5, 0x00a6cd97,
	0xfe54cdd6, 0xff4b1db8, 0x00f8e90c, 0xfe36d2da, 0xfe920d67, 0xffd5c868, 0xfff991fa, 0xfe8937ab,
	0xffbbe00f, 0x0118eb71, 0x00ac04b6, 0xfff061b4, 0xff829649, 0x020303cb, 0x0008364a, 0x015a1123,
	0xfe6a630e, 0xfffc4c54, 0x00b1383d, 0x00bcf9dc, 0x004767bc, 0xffefb7b9, 0xff8057b8, 0xffd4b443,
	0xfdf15997, 0x01512dc1, 0xff7d47d0, 0x017119fc, 0xffb5d66b, 0xffcc43c3, 0x00ad9bb5, 0x004b6f58,
	0xfe3f4c31, 0xffe72e97, 0xff634126, 0xff367eca, 0xfec24f03, 0xff0e13dc, 0x018628c4, 0x0129a25e,
	0xff28a264, 0xff1e043a, 0x004feedb, 0xffa52cf0, 0x01b495b3, 0xfdb27ee3, 0xffc37bbb, 0xfe94d6eb,
	0x01c428f0, 0xff71bfcd, 0x00fe3bc6, 0xfe939b8c, 0x001400c6, 0xff7c2620, 0xfef1d18d, 0xffd991d9,
	0xfee01a13, 0x0070ea4f, 0xfe94e728, 0xffcdc498, 0xffcf6fc1, 0xff03bfed, 0xff357a91, 0x007e42ca,
	0x00c87770, 0xfe7ca325, 0xfee53330, 0xff74e10d, 0x00fa72f9, 0x02959cc7, 0x002dab07, 0x0105489f,
	0x00a40d2b, 0x00c5024a, 0xffab0d03, 0xfebab4f2, 0x0081014b, 0xfe058676, 0xfec17968, 0xffc22a21,
	0xfe577a89, 0x00e2d3d1, 0x01f5b416, 0x0033d49b, 0x00052352, 0xff65f3ca, 0xfd9171ab, 0x00692a7e,
	0xff57e99d, 0x01e09cc4, 0x0057ed98, 0x005642c4, 0xfe3571da, 0x009945fd, 0xff60ce76, 0xfe58c00d,
	0xfef93428, 0xff466e8e, 0xff7e12ac, 0x00f33432, 0x008969e2, 0xffcff150, 0xff3c84fe, 0x009da2a5,
	0xfe23ea5a, 0x00189f37, 0x00ed13b4, 0xff2e1cb7, 0xffc31de3, 0xff0998c8, 0xfec22582, 0x009ae7b3,
	0xff2a5cfe, 0xff6f019d, 0xfe9c22b5, 0x003bdfe7, 0xff78258c, 0x01915780, 0xffde73e1, 0xff3c03d6,
	0xffdf5102, 0x00ae6da8, 0xffd7e118, 0x000abee8, 0xfeeba9c2, 0xfe5cfac8, 0x01c2b619, 0x001f35b1,
	0x006905e4, 0x00acca91, 0xfec6de63, 0x01b1065b, 0xffb47fb0, 0x00cdfbc7, 0x00c721ba, 0x00e3b606,
	0x018d434b, 0x017d1be4, 0xfff265d6, 0x02777a0d, 0x00042b32, 0x00d72121, 0xff6247a6, 0xfe94f114,
	0xff4f99aa, 0xfecd81f1, 0x00237e08, 0xfd30f09b, 0xfff6c953, 0x0024c2b3, 0x01ac6800, 0x0066058a,
	0xfe78ae65, 0xfff4afa9, 0x01777806, 0xff3be9ca, 0x009a6257, 0x01c2bf94, 0xff86f000, 0x025e98fd,
	0x00eed96f, 0x00afa817, 0x00254605, 0xfdd1338f, 0xffa9dffe, 0x005c8c7b, 0xfd3cf2fa, 0x0027ca53,
	0x0110c291, 0xfe0004a6, 0xfffe3845, 0xff14ec9e, 0x0115e58f, 0xff93fe7f, 0xff37b3a3, 0xff87280e,
	0xff119d6f, 0xfe12fcca, 0x017b78b2, 0x001f0a57, 0xff9d2926, 0xffd89ef4, 0x00ef8856, 0x0087dd94,
	0x7206e40d, 0x18f731ee, 0x17092e12, 0x6e55dcab, 0x355c6ab8, 0x7535ea6b, 0x43ce879d, 0x06c60d8c,
	0x6606cc0d, 0x727be4f7, 0x266d4cda, 0x36d56daa, 0x185030a0, 0x35776aee, 0x6c2bd857, 0x64c5c98b,
	0x0f401e80, 0x53a6a74d, 0x78e2f1c5, 0x381a7034, 0x1b1c3638, 0x47c68f8d, 0x59a3b347, 0x51aaa355,
	0x412c8259, 0x0a8f151e, 0x4a9f953f, 0x49f793ef, 0x10c12182, 0x239e473c, 0x5448a891, 0x69bcd379,
	0x497792ef, 0x46b28d65, 0x43b38767, 0x50c6a18d, 0x36b66d6c, 0x511aa235, 0x02410482, 0x7f05fe0b,
	0x647fc8ff, 0x3b6e76dc, 0x107e20fc, 0x73e3e7c7, 0x116522ca, 0x537ea6fd, 0x28495092, 0x57d4afa9,
	0x01d903b2, 0x5288a511, 0x4a36946d, 0x642fc85f, 0x18ab3156, 0x23ae475c, 0x3a307460, 0x7d3cfa79,
	0x58ceb19d, 0x6ea6dd4d, 0x2f635ec6, 0x328e651c, 0x345c68b8, 0x3ab47568, 0x3b5976b2, 0x19933326,
	0x4cd999b3, 0x3dd57baa, 0x2c6258c4, 0x36696cd2, 0x08bc1178, 0x2c3d587a, 0x6f3ade75, 0x66f3cde7,
	0x222b4456, 0x1c043808, 0x33e667cc, 0x042d085a, 0x1307260e, 0x511da23b, 0x59dfb3bf, 0x2dbc5b78,
	0x02280450, 0x05870b0e, 0x6772cee5, 0x73cae795, 0x15ea2bd4, 0x01c7038e, 0x106720ce, 0x5310a621,
	0x4fe89fd1, 0x1995332a, 0x0fe11fc2, 0x37346e68, 0x5607ac0f, 0x60d6c1ad, 0x5985b30b, 0x7756eead,
	0x4cb7996f, 0x2cca5994, 0x65decbbd, 0x00e601cc, 0x26754cea, 0x35876b0e, 0x1e003c00, 0x24b84970,
	0x0c941928, 0x6ba6d74d, 0x2a6c54d8, 0x3a5a74b4, 0x453e8a7d, 0x563cac79, 0x29345268, 0x0da51b4a,
	0x3ab6756c, 0x0d0c1a18, 0x0f601ec0, 0x4a929525, 0x07df0fbe, 0x22fa45f4, 0x398f731e, 0x5b4fb69f,
	0x2e025c04, 0x14c32986, 0x6fe2dfc5, 0x6c92d925, 0x57ccaf99, 0x0fec1fd8, 0x6115c22b, 0x0c2e185c,
	0x4d969b2d, 0x25f84bf0, 0x58efb1df, 0x15e42bc8, 0x7eeafdd5, 0x3fde7fbc, 0x35dd6bba, 0x627bc4f7,
	0x45428a85, 0x65bacb75, 0x61dac3b5, 0x6d12da25, 0x44128825, 0x2ec35d86, 0x5291a523, 0x62b6c56d,
	0x0a091412, 0x6d7ddafb, 0x54c6a98d, 0x5030a061, 0x5794af29, 0x6c30d861, 0x26f24de4, 0x6220c441,
	0x2ea55d4a, 0x4d989b31, 0x272d4e5a, 0x6b50d6a1, 0x0fb21f64, 0x65decbbd, 0x185130a2, 0x25424a84,
	0x08001000, 0x1fc73f8e, 0x425d84bb, 0x5f0bbe17, 0x7521ea43, 0x422c8459, 0x7217e42f, 0x0e641cc8,
	0x21bc4378, 0x29aa5354, 0x1bf637ec, 0x76ffedff, 0x1f8c3f18, 0x4a9a9535, 0x263e4c7c, 0x5c17b82f,
	0x02ab0556, 0x0f431e86, 0x1e6d3cda, 0x704be097, 0x6211c423, 0x664fcc9f, 0x5dd6bbad, 0x77acef59,
	0x415782af, 0x157c2af8, 0x618cc319, 0x5015a02b, 0x47c18f83, 0x24944928, 0x5981b303, 0x53bba777,
	0x687cd0f9, 0x749fe93f, 0x32ef65de, 0x4a049409, 0x6024c049, 0x5757aeaf, 0x21f743ee, 0x5a9db53b,
	0x2b8a5714, 0x3adc75b8, 0x6e89dd13, 0x36c76d8e, 0x5bb3b767, 0x3da97b52, 0x08831106, 0x6cf1d9e3,
	0x6b24d649, 0x3ec77d8e, 0x271d4e3a, 0x1a8c3518, 0x785cf0b9, 0x3e407c80, 0x7784ef09, 0x701be037,
	0x09a31346, 0x21d743ae, 0x1ec53d8a, 0x3b897712, 0x3e027c04, 0x31f663ec, 0x12ed25da, 0x6cc0d981,
	0x0f931f26, 0x62e8c5d1, 0x0f6e1edc, 0x487790ef, 0x0afb15f6, 0x3e487c90, 0x28c5518a, 0x3d4b7a96,
	0x20344068, 0x00ba0174, 0x435a86b5, 0x0f121e24, 0x7090e121, 0x3fd97fb2, 0x71a8e351, 0x4c6c98d9,
	0x3dfa7bf4, 0x2c7058e0, 0x7d9dfb3b, 0x429a8535, 0x5f7fbeff, 0x44ec89d9, 0x21444288, 0x6394c729,
	0x5f0ebe1d, 0x0c111822, 0x32a16542, 0x5255a4ab, 0x247c48f8, 0x17ed2fda, 0x46dd8dbb, 0x097a12f4,
	0x51cba397, 0x0d0a1a14, 0x10a32146, 0x500ba017, 0x34ac6958, 0x59e8b3d1, 0x7dc9fb93, 0x7099e133,
	0x7142e285, 0x46aa8d55, 0x5833b067, 0x6689cd13, 0x4a299453, 0x2d105a20, 0x6df4dbe9, 0x75afeb5f,
};

typedef enum {
	FFT_FUNC_KIND_REAL_FFT,
	FFT_FUNC_KIND_COMPLEX_FFT,
	FFT_FUNC_KIND_REAL_IFFT,
	FFT_FUNC_KIND_COMPLEX_IFFT,
	FFT_FUNC_KIND_POWER_SPECTRUM,
} mca_fft_func_kind_t;

typedef struct {
	mca_fft_func_kind_t func_kind;
	csky_mca_fft_len_t fft_len;
	size_t fft_input_len;
	const fxp32_t *raw_input;
} mca_fft_test_params;

static void gen_mca_fft_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs);

static bool test_mca_fft_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs);

static size_t get_fft_len_from_enum(csky_mca_fft_len_t fft_len) {
	return 512 / fft_len;
}

static bool test_mca_fft_fxp32(
	mca_fft_func_kind_t func_kind,
	csky_mca_fft_len_t fft_len,
	size_t *fft_input_len_array,
	size_t num_fft_input_len_array) {
	bool total_passed = true, passed;

	if (fft_input_len_array == NULL) {
		num_fft_input_len_array = 1;
	}
	for (size_t i = 0; i < num_fft_input_len_array; ++i) {
		size_t input_size = get_fft_len_from_enum(fft_len);
		size_t output_size = input_size;
		if (func_kind == FFT_FUNC_KIND_POWER_SPECTRUM) {
			output_size = (output_size / 2 + 1) * 2;
		}
		else if (func_kind == FFT_FUNC_KIND_COMPLEX_FFT ||
			func_kind == FFT_FUNC_KIND_COMPLEX_IFFT) {
			input_size *= 2;
			output_size *= 2;
		}
		if ((func_kind == FFT_FUNC_KIND_REAL_FFT ||
			func_kind == FFT_FUNC_KIND_POWER_SPECTRUM) &&
			fft_input_len_array != NULL) {
			input_size = fft_input_len_array[i];
		}
		mca_cache_block_t cache_blocks[] = {
			// Input
			{
				.type = MCA_FXP32,
				.count = input_size,
			},
			// Output
			{
				.type = MCA_FXP32,
				.count = output_size,
			},
		};

		mca_test_block_t test_blocks[] = {
			// Input
			{
				.type = MCA_FXP32,
				.count = input_size,
				.aligns = align_0 | align_4 | align_8 | align_c,
				.io_dir = io_dir_input,
				.cache_index = 0,
			},
			// Output
			{
				.type = MCA_FXP32,
				.count = output_size,
				.aligns = align_0 | align_4 | align_8 | align_c,
				.io_dir = io_dir_output,
				.cache_index = 1,
				.tolerance = 0,
			},
		};

		mca_fft_test_params params = {
			.func_kind = func_kind,
			.fft_len = fft_len,
			.fft_input_len = input_size,
			.raw_input = SAMPLE_INPUT_DATA,
		};

		passed = mca_generic_hardware_test(
			&params,
			gen_mca_fft_golden_data,
			cache_blocks,
			sizeof(cache_blocks) / sizeof(cache_blocks[0]),
			test_mca_fft_kernal,
			test_blocks,
			sizeof(test_blocks) / sizeof(test_blocks[0]));

		if (!passed) {
			print_log("Failed for input size %d.\n", input_size);
			total_passed = false;
		}
	}

	return total_passed;
}

bool test_mca_rfft_512_fxp32() {
	size_t fft_input_len[] = { 1, 17, 256, 393, 512 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_FFT, CSKY_MCA_FFT_LEN_512,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_rfft_256_fxp32() {
	size_t fft_input_len[] = { 1, 17, 128, 193, 256 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_FFT, CSKY_MCA_FFT_LEN_256,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_rfft_128_fxp32() {
	size_t fft_input_len[] = { 1, 17, 64, 93, 128 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_FFT, CSKY_MCA_FFT_LEN_128,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_rfft_64_fxp32() {
	size_t fft_input_len[] = { 1, 17, 32, 53, 64 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_FFT, CSKY_MCA_FFT_LEN_64,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_rfft_32_fxp32() {
	size_t fft_input_len[] = { 1, 7, 16, 23, 32 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_FFT, CSKY_MCA_FFT_LEN_32,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_rfft_16_fxp32() {
	size_t fft_input_len[] = { 1, 5, 8, 13, 16 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_FFT, CSKY_MCA_FFT_LEN_16,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}

bool test_mca_cfft_512_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_FFT, CSKY_MCA_FFT_LEN_512, NULL, 0);
}
bool test_mca_cfft_256_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_FFT, CSKY_MCA_FFT_LEN_256, NULL, 0);
}
bool test_mca_cfft_128_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_FFT, CSKY_MCA_FFT_LEN_128, NULL, 0);
}
bool test_mca_cfft_64_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_FFT, CSKY_MCA_FFT_LEN_64, NULL, 0);
}
bool test_mca_cfft_32_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_FFT, CSKY_MCA_FFT_LEN_32, NULL, 0);
}
bool test_mca_cfft_16_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_FFT, CSKY_MCA_FFT_LEN_16, NULL, 0);
}

bool test_mca_rifft_512_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_IFFT, CSKY_MCA_FFT_LEN_512, NULL, 0);
}
bool test_mca_rifft_256_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_IFFT, CSKY_MCA_FFT_LEN_256, NULL, 0);
}
bool test_mca_rifft_128_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_IFFT, CSKY_MCA_FFT_LEN_128, NULL, 0);
}
bool test_mca_rifft_64_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_IFFT, CSKY_MCA_FFT_LEN_64, NULL, 0);
}
bool test_mca_rifft_32_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_IFFT, CSKY_MCA_FFT_LEN_32, NULL, 0);
}
bool test_mca_rifft_16_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_REAL_IFFT, CSKY_MCA_FFT_LEN_16, NULL, 0);
}

bool test_mca_cifft_512_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_IFFT, CSKY_MCA_FFT_LEN_512, NULL, 0);
}
bool test_mca_cifft_256_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_IFFT, CSKY_MCA_FFT_LEN_256, NULL, 0);
}
bool test_mca_cifft_128_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_IFFT, CSKY_MCA_FFT_LEN_128, NULL, 0);
}
bool test_mca_cifft_64_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_IFFT, CSKY_MCA_FFT_LEN_64, NULL, 0);
}
bool test_mca_cifft_32_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_IFFT, CSKY_MCA_FFT_LEN_32, NULL, 0);
}
bool test_mca_cifft_16_fxp32() {
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_COMPLEX_IFFT, CSKY_MCA_FFT_LEN_16, NULL, 0);
}

bool test_mca_power_spectrum_512_fxp32() {
	size_t fft_input_len[] = { 1, 17, 256, 393, 512 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_POWER_SPECTRUM, CSKY_MCA_FFT_LEN_512,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_power_spectrum_256_fxp32() {
	size_t fft_input_len[] = { 1, 17, 128, 193, 256 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_POWER_SPECTRUM, CSKY_MCA_FFT_LEN_256,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_power_spectrum_128_fxp32() {
	size_t fft_input_len[] = { 1, 17, 64, 93, 128 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_POWER_SPECTRUM, CSKY_MCA_FFT_LEN_128,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_power_spectrum_64_fxp32() {
	size_t fft_input_len[] = { 1, 17, 32, 53, 64 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_POWER_SPECTRUM, CSKY_MCA_FFT_LEN_64,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_power_spectrum_32_fxp32() {
	size_t fft_input_len[] = { 1, 7, 16, 23, 32 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_POWER_SPECTRUM, CSKY_MCA_FFT_LEN_32,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}
bool test_mca_power_spectrum_16_fxp32() {
	size_t fft_input_len[] = { 1, 5, 8, 13, 16 };
	return test_mca_fft_fxp32(
		FFT_FUNC_KIND_POWER_SPECTRUM, CSKY_MCA_FFT_LEN_16,
		fft_input_len, sizeof(fft_input_len) / sizeof(fft_input_len[0]));
}

void gen_mca_fft_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs) {
	mca_fft_test_params *tp = params;

	fxp32_t *input_ptr = (fxp32_t *)cache_ptrs[0];
	fxp32_t *output_ptr = (fxp32_t *)cache_ptrs[1];
	generate_random_data_fxp(input_ptr, 4, tp->fft_input_len);

	switch (tp->func_kind) {
	case FFT_FUNC_KIND_REAL_FFT:
		switch (tp->fft_len) {
		case CSKY_MCA_FFT_LEN_512:
			real_fft_fxp_512(input_ptr, tp->fft_input_len, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_256:
			real_fft_fxp_256(input_ptr, tp->fft_input_len, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_128:
			real_fft_fxp_128(input_ptr, tp->fft_input_len, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_64:
			real_fft_fxp_64(input_ptr, tp->fft_input_len, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_32:
			real_fft_fxp_32(input_ptr, tp->fft_input_len, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_16:
			real_fft_fxp_16(input_ptr, tp->fft_input_len, output_ptr);
			break;
		}
		break;
	case FFT_FUNC_KIND_COMPLEX_FFT:
		switch (tp->fft_len) {
		case CSKY_MCA_FFT_LEN_512:
			complex_fft_fxp_512(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_256:
			complex_fft_fxp_256(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_128:
			complex_fft_fxp_128(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_64:
			complex_fft_fxp_64(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_32:
			complex_fft_fxp_32(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_16:
			complex_fft_fxp_16(input_ptr, output_ptr);
			break;
		}
		break;
	case FFT_FUNC_KIND_REAL_IFFT:
		switch (tp->fft_len) {
		case CSKY_MCA_FFT_LEN_512:
			real_ifft_fxp_512(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_256:
			real_ifft_fxp_256(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_128:
			real_ifft_fxp_128(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_64:
			real_ifft_fxp_64(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_32:
			real_ifft_fxp_32(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_16:
			real_ifft_fxp_16(input_ptr, output_ptr);
			break;
		}
		break;
	case FFT_FUNC_KIND_COMPLEX_IFFT:
		switch (tp->fft_len) {
		case CSKY_MCA_FFT_LEN_512:
			complex_ifft_fxp_512(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_256:
			complex_ifft_fxp_256(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_128:
			complex_ifft_fxp_128(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_64:
			complex_ifft_fxp_64(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_32:
			complex_ifft_fxp_32(input_ptr, output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_16:
			complex_ifft_fxp_16(input_ptr, output_ptr);
			break;
		}
		break;
	case FFT_FUNC_KIND_POWER_SPECTRUM:
		switch (tp->fft_len) {
		case CSKY_MCA_FFT_LEN_512:
			power_spectrum_fxp_512(input_ptr, tp->fft_input_len,
				(fxp64_t *)output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_256:
			power_spectrum_fxp_256(input_ptr, tp->fft_input_len,
				(fxp64_t *)output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_128:
			power_spectrum_fxp_128(input_ptr, tp->fft_input_len,
				(fxp64_t *)output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_64:
			power_spectrum_fxp_64(input_ptr, tp->fft_input_len,
				(fxp64_t *)output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_32:
			power_spectrum_fxp_32(input_ptr, tp->fft_input_len,
				(fxp64_t *)output_ptr);
			break;
		case CSKY_MCA_FFT_LEN_16:
			power_spectrum_fxp_16(input_ptr, tp->fft_input_len,
				(fxp64_t *)output_ptr);
			break;
		}
		break;
	}
}

bool test_mca_fft_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs) {
	mca_fft_test_params *tp = params;

	fxp32_t *input = (fxp32_t *)block_ptrs[0];
	fxp32_t *output = (fxp32_t *)block_ptrs[1];
	
	switch (tp->func_kind) {
	case FFT_FUNC_KIND_REAL_FFT:
		csky_mca_rfft_fxp32(tp->fft_len, input, tp->fft_input_len, output);
		break;
	case FFT_FUNC_KIND_COMPLEX_FFT:
		csky_mca_cfft_fxp32(tp->fft_len, input, output);
		break;
	case FFT_FUNC_KIND_REAL_IFFT:
		csky_mca_rifft_fxp32(tp->fft_len, input, output);
		break;
	case FFT_FUNC_KIND_COMPLEX_IFFT:
		csky_mca_cifft_fxp32(tp->fft_len, input, output);
		break;
	case FFT_FUNC_KIND_POWER_SPECTRUM:
		csky_mca_power_spectrum_fxp32(tp->fft_len, input, tp->fft_input_len,
			(fxp64_t *)output);
		break;
	}

	return true;
}
