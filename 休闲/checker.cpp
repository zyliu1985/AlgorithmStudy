#include "testlib.h"

bool mp[7][7] = {{0, 0, 0, 0, 0, 0, 0}, 
	             {0, 0, 0, 0, 0, 0, 0},
				 {0, 0, 0, 0, 0, 0, 0},
				 {0, 0, 0, 0, 0, 0, 0},
				 {0, 0, 0, 0, 0, 0, 0},
				 {0, 0, 0, 0, 0, 0, 0},
				 {0, 0, 0, 0, 0, 0, 0}}
int main(int argc, char* argv[]) {
    setName("compares two doubles");
    registerTestlibCmd(argc, argv); // 初始化 checker，必须在最前面调用一次。
    
    
    
    
    
    
    
    double pans = ouf.readDouble(); // 从选手输出读取一个 double 类型变量
    double jans = ans.readDouble(); // 从标准答案读取一个 double 类型变量

    if (fabs(pans - jans) < 0.02) // 如果差值小于 0.01，返回答案正确
        quitf(_ok, "The answer is correct.");
    else // 否则返回答案错误
        quitf(_wa, "The answer is wrong: expected = %f, found = %f", jans, pans);
}
