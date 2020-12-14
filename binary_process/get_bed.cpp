//#include<iostream>
//#include<vector>
//#include<io.h>
//#include<fstream>
//#include<assert.h>
//#include<string>
//
//using namespace std;
//
//int main() {
//	std::fstream fr;
//	std::fstream fr1;
//	std::fstream fw;
//
//	for (int i = 3;i < 4;i++) {
//		for (int j = 1;j < 6;j++) {
//			std::string ii = std::to_string(i);
//			ii = '0' + ii;
//			std::string jj = std::to_string(j);
//			std::string jjj = std::to_string(j-1);
//
//			fr.open("D:\\bone_leison\\"+ii+"\\bed"+jj+"\\mumap_bed_"+jjj+".map", std::ios::binary | std::ios::in);
//			fr1.open("D:\\bone_leison\\" + ii + "\\bed" + jj + "\\mumap_without_bed_" + jjj + ".map", std::ios::binary | std::ios::in);
//			fw.open("D:\\bone_leison\\" + ii + "\\bed" + jj + "\\bed_" + jjj + ".map", std::ios::binary | std::ios::out);
//			char* pRead = new char[299 * 299 * 223 * 4]();
//			char* pRead1 = new char[299 * 299 * 223 * 4]();
//			char* pwrite = new char[299 * 299 * 223 * 4]();
//			fr.read((char*)&pRead[0], 299 * 299 * 223 * 4);
//			fr1.read((char*)&pRead1[0], 299 * 299 * 223 * 4);
//			//fw.read((char*)&pwrite[0], 299 * 299 * 223 * 4);
//
//			float* pfloatR, *pfloatW, *pfloatR1;
//			pfloatR = (float*)pRead;
//			pfloatR1 = (float*)pRead1;
//			pfloatW = (float*)pwrite;
//
//			for (int i = 0; i != 299 * 299 * 223; i++) {
//				pfloatW[i] = pfloatR1[i] - pfloatR[i];
//			}
//
//			fr.close();
//			fr1.close();
//
//			fw.write((char*)&pwrite[0], 299 * 299 * 223 * 4);
//			fw.close();
//
//
//		}
//	}
//
//
//	system("pause");
//}
//
//
