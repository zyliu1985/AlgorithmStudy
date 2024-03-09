#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <vector>
#ifdef __linux__
#include <termio.h>
int getch() // 不回显函数
{
    struct termios nts, ots;
    // 得到当前终端(0表示标准输入)的设置
    if (tcgetattr(0, &ots) < 0) return EOF;
    // 设置终端为Raw原始模式，该模式下所有的输入数据以字节为单位被处理
    nts = ots;
    cfmakeraw(&nts); 
    // 设置上更改之后的设置
    if (tcsetattr(0, TCSANOW, &nts) < 0) return EOF;
    // 设置还原成老的模式
    int cr;
    cr = getchar();
    if (tcsetattr(0, TCSANOW, &ots) < 0)  return EOF;
    return cr;
}
#endif
#ifdef __APPLE__
int getch()
{
    system("stty -icanon");
    char c = getchar();
    system("stty icanon");
    return c;
}
#endif
#if !defined __linux__ && !defined __APPLE__ 
#include <conio.h>
#define _WINDOWS
#endif

using namespace std;

const int BLACK = 1;
const int WHITE = -1;
const int INF = 100000000;
int num[10][10]; // 值为0表示没有值，非0表示有数据，越界为正无穷
int rd = 0; // 回合数
int pos = 1; // 所在列
int color = BLACK; // 黑先
int maxD = 4; // 最大深度

void clear()
{
    getch();
	#ifdef _WINDOWS
		system("cls");
	#else
    	cout << "\033c" << flush;
	#endif
}

void moveDown() // 向下移动
{   
    rd++;
    for (int i = 6; i >= 1; i--)
    {
        if (num[i][pos] == 0)
        {
            // if (color == BLACK) cout << " ● ";
            // else cout << " ○ ";
            // cout << "下在了 " << i << " 行 " << pos << " 列" << endl;
            num[i][pos] = color;
            color *= -1;
            return;
        }
    }
}

void moveRight() // 向右移动
{   
    if (pos < 7) pos++;
}

void moveLeft() // 向左移动
{   
    if (pos > 1) pos--;
}

void place(int p, int player) // 放置棋子
{   
    for (int i = 6; i >= 1; i--)
    {
        if (num[i][p] == 0)
        {
            num[i][p] = player;
            return;
        }
    }
}

void remove(int p) // 移走棋子
{   
    for (int i = 1; i <= 6; i++)
    {
        if (num[i][p] != 0)
        {
            num[i][p] = 0;
            return;
        }
    }
}

int findWinner() // 判断游戏是否结束
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (num[i][j] == 0) continue;
            // 竖
            if (i + 3 <= 6 && num[i][j] == num[i+1][j] && num[i][j] == num[i+2][j] && num[i][j] == num[i+3][j])
                return num[i][j];
            // 横
            if (j + 3 <= 7 && num[i][j] == num[i][j+1] && num[i][j] == num[i][j+2] && num[i][j] == num[i][j+3])
                return num[i][j];
            // 斜
            if (i + 3 <= 6 && j + 3 <= 7 && num[i][j] == num[i+1][j+1] && num[i][j] == num[i+2][j+2] && num[i][j] == num[i+3][j+3])
                return num[i][j];
            // 斜
            if (i + 3 <= 6 && j - 3 >= 1 && num[i][j] == num[i+1][j-1] && num[i][j] == num[i+2][j-2] && num[i][j] == num[i+3][j-3])
                return num[i][j];
        }
    }
    return 0;
}

bool tie() // 判断平局
{
    for (int j = 1; j <= 7; j++)
    {
        if (num[1][j] == 0) return false;
    }
    return true;
}

void drawBoard() // 打印当前表格
{
    cout << "   ";
    for (int i = 1; i <= 7; i++) 
    {
        if (i == pos)
        {
			#ifdef _WINDOWS	
            	if (color == BLACK) cout << " ●";
            	else cout << " ○";
            #else
            	if (color == BLACK) cout << " ●  ";
            	else cout << " ○  ";
            #endif
        }
        else cout << "    ";
    }
    cout << "\n";
    // 输出上边框
    cout << "  ╔";
    for (int i = 1; i <= 6; i++) cout << "═══╤";
    cout << "═══╗\n";
    // 输出中间部分
    for (int i = 1; i <= 6; i++) // 行
    {
        cout << "  ║";
        for (int j = 1; j <= 7; j++) // 列
        {
            if (num[i][j] == BLACK)
            {
            	#ifdef _WINDOWS	
                	cout << " ● ";
                #else
                	cout << " ● ";
                #endif
            } 
            else if (num[i][j] == WHITE)
            {
            	#ifdef _WINDOWS	
                	cout << " ○ ";
                #else
                	cout << " ○ ";
                #endif
            }
            else cout << "   ";
            if (j != 7)
                cout << "│";
            else
                cout << "║";
        }
        cout << " \n";
        // 输出下边框
        if (i != 6)
        {
            cout << "  ╟";
            for (int i = 1; i <= 6; i++) cout << "───┼";
            cout << "───╢\n";
        }
        else
        {
            cout << "  ╚";
            for (int i = 1; i <= 6; i++) cout << "═══╧";
            cout << "═══╝\n";
        }
    }
}

// 有 两个自由端的3子 +500分
// 有 一个自由端的3子 +100分
// 有 两个自由端的2子 +100分
// 有 一个自由端的2子 +10分

namespace pipi
{
    int eval(int player) // 评估player角色当前的得分
    {
        int value = 0;
        // 横向检测
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i][j] == player)
                {
                    while (num[i][j + cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i][j-1] == 0) free++; // 左端
                    if (num[i][j+cnt] == 0) free++; // 右端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    j += cnt;
                }
            }
        }
        // cout << value << endl;
        // 纵向检测
        for (int j = 1; j <= 7; j++)
        {
            for (int i = 1; i <= 6; i++)
            {
                int cnt = 0, free = 0;
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j] == 0) free++; // 上端
                    if (num[i+cnt][j] == 0) free++; // 下端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    i += cnt;
                }
            }
        }
        // cout << value << endl;
        // 左上右下斜线检测
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j-1] == player) continue; // 只判断第一个点
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j+cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j-1] == 0) free++; // 左上端
                    if (num[i+cnt][j+cnt] == 0) free++; // 右下端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                }
            }
        }
        // cout << value << endl;
        // 右上左下斜线检测
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j+1] == player) continue; // 只判断第一个点
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j-cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j+1] == 0) free++; // 右上端
                    if (num[i+cnt][j-cnt] == 0) free++; // 左下端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                }
            }
        }
        // cout << value << endl;
        return value;
    }

    int a[55];
    vector<int> bestMove;

    int miniMax(int step, int player)
    {
        if (findWinner() == player) // 获胜，评分最大
            return INF;
        if (findWinner() == -1*player) // 失败，评分最小
            return -INF;
        if (step > maxD)
        {
            int ans = eval(player) - eval(-1*player);
            return ans;
        }
        int value[10] = {};
        if (step % 2 == 1) // max最大，角色player
        {
            int maxV = -1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // 能下i列
                {
                    a[step] = i;
                    place(i, player);
                    int v = miniMax(step + 1, player);
                    if (step == 1) value[i] = v; 
                    if (v > maxV)
                    {
                        maxV = v;
                    }
                    remove(i);
                }
            }
            if (step == 1)
            {
                bestMove.clear();
                for (int i = 1; i <= 7; i++)
                {
                    if (value[i] == maxV)
                    {
                        bestMove.push_back(i);
                    }
                }
            }
            return maxV;
        }
        else // min最小，角色-1*player
        {
            int minV = 1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // 能下i列
                {
                    a[step] = i;
                    place(i, -1*player);
                    int v = miniMax(step + 1, player);
                    minV = min(minV, v);
                    remove(i);
                }
            }
            return minV;
        }
    }

    int strategy(int player)
    {
        miniMax(1, player);
        int cc = rand() % bestMove.size();
        return bestMove[cc];
    }
}

namespace pipi2
{
    int eval(int player) // 评估player角色当前的得分
    {
        int value = 0;
        // 横向检测
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i][j] == player)
                {
                    while (num[i][j + cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i][j-1] == 0) free++; // 左端
                    if (num[i][j+cnt] == 0) free++; // 右端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    j += cnt;
                }
            }
        }
        // cout << value << endl;
        // 纵向检测
        for (int j = 1; j <= 7; j++)
        {
            for (int i = 1; i <= 6; i++)
            {
                int cnt = 0, free = 0;
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j] == 0) free++; // 上端
                    if (num[i+cnt][j] == 0) free++; // 下端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    i += cnt;
                }
            }
        }
        // cout << value << endl;
        // 左上右下斜线检测
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j-1] == player) continue; // 只判断第一个点
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j+cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j-1] == 0) free++; // 左上端
                    if (num[i+cnt][j+cnt] == 0) free++; // 右下端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                }
            }
        }
        // cout << value << endl;
        // 右上左下斜线检测
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j+1] == player) continue; // 只判断第一个点
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j-cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j+1] == 0) free++; // 右上端
                    if (num[i+cnt][j-cnt] == 0) free++; // 左下端
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                }
            }
        }
        // cout << value << endl;
        return value;
    }

    int a[55];
    vector<int> bestMove;

    int miniMax(int step, int player)
    {
        if (findWinner() == player) // 获胜，评分最大
            return INF;
        if (findWinner() == -1*player) // 失败，评分最小
            return -INF;
        if (step > maxD)
        {
            int ans = eval(player) - eval(-1*player);
            return ans;
        }
        int value[10] = {};
        if (step % 2 == 1) // max最大，角色player
        {
            int maxV = -1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // 能下i列
                {
                    a[step] = i;
                    place(i, player);
                    int v = miniMax(step + 1, player);
                    if (step == 1) value[i] = v; 
                    if (v > maxV)
                    {
                        maxV = v;
                    }
                    remove(i);
                }
            }
            if (step == 1)
            {
                bestMove.clear();
                for (int i = 1; i <= 7; i++)
                {
                    if (value[i] == maxV)
                    {
                        bestMove.push_back(i);
                    }
                }
            }
            return maxV;
        }
        else // min最小，角色-1*player
        {
            int minV = 1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // 能下i列
                {
                    a[step] = i;
                    place(i, -1*player);
                    int v = miniMax(step + 1, player);
                    minV = min(minV, v);
                    remove(i);
                }
            }
            return minV;
        }
    }

    int strategy(int player)
    {
        miniMax(1, player);
        int cc = rand() % bestMove.size();
        return bestMove[cc];
    }
}


int game() // 开始游戏
{
    clear();
    cout << "**********************************" << endl;
    cout << "—————————— Ready Go～ ————————————" << endl;
    cout << "**********************************" << endl;
    getch();

    char ch = 0;
    while (true) // 当游戏没结束时
    {
        pos = pipi::strategy(BLACK);
        moveDown();
        clear();
        drawBoard(); // 打印棋盘
        int winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                cout << " ● ";
            } 
            else if (winner == WHITE)
            {
                cout << " ○ ";
            }
            cout << "获胜" << endl;
            return winner;
        }
        if (tie()) // 判断平局
        {
            cout << "平局" << endl;
            return 0;
        }

        // 电脑
        pos = pipi2::strategy(WHITE);
        moveDown();
        clear();
        drawBoard(); // 打印棋盘
        winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                cout << " ● ";
            } 
            else if (winner == WHITE)
            {
                cout << " ○ ";
            }
            cout << "获胜" << endl;
            return winner;
        }
        if (tie()) // 判断平局
        {
            cout << "平局" << endl;
            return 0;
        }
    }
}

int game2() // 无输出游戏
{
    // clear();
    // cout << "**********************************" << endl;
    // cout << "—————————— Ready Go～ ————————————" << endl;
    // cout << "**********************************" << endl;
    // getch();

    char ch = 0;
    while (true) // 当游戏没结束时
    {
        pos = pipi::strategy(BLACK);
        moveDown();
        // clear();
        // drawBoard(); // 打印棋盘
        int winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                // cout << " ● ";
            } 
            else if (winner == WHITE)
            {
                // cout << " ○ ";
            }
            // cout << "获胜" << endl;
            return winner;
        }
        if (tie()) // 判断平局
        {
            // cout << "平局" << endl;
            return 0;
        }

        // 电脑
        pos = pipi2::strategy(WHITE);
        moveDown();
        // clear();
        // drawBoard(); // 打印棋盘
        winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                // cout << " ● ";
            } 
            else if (winner == WHITE)
            {
                // cout << " ○ ";
            }
            // cout << "获胜" << endl;
            return winner;
        }
        if (tie()) // 判断平局
        {
            // cout << "平局" << endl;
            return 0;
        }
    }
}

void intro() // 游戏规则展示
{
    cout << "***********************************************************" << endl;
    cout << "欢迎来到 四子棋 游戏～" << endl;
    cout << "在这个游戏里会有一个 6*7 的表格" << endl;
    cout << "可以选择 ←、↓、→，选择某一列" << endl;
    cout << "当 上下或斜线上四子连成一条直线 游戏结束！" << endl; 
    cout << "点击【ENTER】开始游戏" << endl;
    cout << "点击【ESC】退出游戏" << endl;
    cout << "***********************************************************" << endl;
}

void init()
{
	srand(time(0));
	memset(num, 999999, sizeof(num));
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 7; j++)
            num[i][j] = 0;
	rd = 0; // 回合数
	pos = 1; // 所在列
	color = BLACK; // 黑先
}

int main()
{
    init();
    int cnta = 0, cntb = 0, cntc = 0; // 黑胜 白胜 平局
    cout << "请按任意键开始第一回合~" << endl;
    int winner = game();
    if (winner == 1) cnta++;
    else if (winner == -1) cntb++;
    else if (winner == 0) cntc++;
    for (int t = 2; t <= 5; t++)
    {
        memset(num, 999999, sizeof(num));
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 7; j++)
                num[i][j] = 0;
        winner = game2();
        if (winner == 1) cnta++;
        else if (winner == -1) cntb++;
        else if (winner == 0) cntc++;
        if (winner == 1)
        	cout << "第" << t << "局结果：" << " ● 获胜" << endl;
        else if (winner == -1)
        	cout << "第" << t << "局结果：" << " ○ 获胜" << endl;
        else
        	cout << "第" << t << "局结果：" << "平局" << endl;
    }
    cout << "黑胜: " << cnta << endl;
    cout << "白胜: " << cntb << endl;
    cout << "平局: " << cntc << endl;
    return 0;
}