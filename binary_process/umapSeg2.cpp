////#include<iostream>
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
//	std::fstream fw1;
//	//for (int i = 1;i < 4;i++) {
//		for (int j = 1;j < 6;j++) {
//			//std::string ii = std::to_string(i);
//			//ii = '0' + ii;
//			std::string jj = std::to_string(j);
//			std::string jjj = std::to_string(j - 1);
//
//			fr1.open("E:\\paste_bone\\AImrUmap\\bed" + jj + "\\mumap_bed_" + jjj + ".map", std::ios::binary | std::ios::in);
//			fr. open("E:\\paste_bone\\mrUmap\\bed" + jj + "\\mumap_bed_" + jjj + ".map", std::ios::binary | std::ios::in);
//
//			char* pRead = new char[299 * 299 * 223 * 4]();
//			char* pRead1 = new char[299 * 299 * 223 * 4]();
//			char* pwrite = new char[299 * 299 * 223 * 4]();
//			char* pwrite1 = new char[299 * 299 * 223 * 4]();
//			fr.read((char*)&pRead[0], 299 * 299 * 223 * 4);
//			fr1.read((char*)&pRead1[0], 299 * 299 * 223 * 4);
//			fr.close();
//			fr1.close();
//			float* pfloatR, *pfloatW, *pfloatR1, *pfloatW1;
//			pfloatR = (float*)pRead;
//			pfloatR1 = (float*)pRead1;
//			pfloatW = (float*)pwrite;
//			pfloatW1 = (float*)pwrite1;
//			for (int i = 0; i != 299 * 299 * 223; i++) {
//				if ((pfloatR1[i] - pfloatR[i])> 0.0003 && pfloatR[i] > 0.0096) {
//					pfloatR[i] = pfloatR1[i]+0.001;
//				}
//			}
//			fw.open("E:\\paste_bone\\newAIUmap\\bed" + jj + "\\mumap_bed_" + jjj + ".map", std::ios::binary | std::ios::out);
//			fw.write((char*)&pRead[0], 299 * 299 * 223 * 4);
//			fw.close();
//
//		}
//	//}
//
//	system("pause");
//}
//
//
