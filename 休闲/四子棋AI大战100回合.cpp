#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <vector>
#ifdef __linux__
#include <termio.h>
int getch() // �����Ժ���
{
    struct termios nts, ots;
    // �õ���ǰ�ն�(0��ʾ��׼����)������
    if (tcgetattr(0, &ots) < 0) return EOF;
    // �����ն�ΪRawԭʼģʽ����ģʽ�����е������������ֽ�Ϊ��λ������
    nts = ots;
    cfmakeraw(&nts); 
    // �����ϸ���֮�������
    if (tcsetattr(0, TCSANOW, &nts) < 0) return EOF;
    // ���û�ԭ���ϵ�ģʽ
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
int num[10][10]; // ֵΪ0��ʾû��ֵ����0��ʾ�����ݣ�Խ��Ϊ������
int rd = 0; // �غ���
int pos = 1; // ������
int color = BLACK; // ����
int maxD = 4; // ������

void clear()
{
    getch();
	#ifdef _WINDOWS
		system("cls");
	#else
    	cout << "\033c" << flush;
	#endif
}

void moveDown() // �����ƶ�
{   
    rd++;
    for (int i = 6; i >= 1; i--)
    {
        if (num[i][pos] == 0)
        {
            // if (color == BLACK) cout << " �� ";
            // else cout << " �� ";
            // cout << "������ " << i << " �� " << pos << " ��" << endl;
            num[i][pos] = color;
            color *= -1;
            return;
        }
    }
}

void moveRight() // �����ƶ�
{   
    if (pos < 7) pos++;
}

void moveLeft() // �����ƶ�
{   
    if (pos > 1) pos--;
}

void place(int p, int player) // ��������
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

void remove(int p) // ��������
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

int findWinner() // �ж���Ϸ�Ƿ����
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (num[i][j] == 0) continue;
            // ��
            if (i + 3 <= 6 && num[i][j] == num[i+1][j] && num[i][j] == num[i+2][j] && num[i][j] == num[i+3][j])
                return num[i][j];
            // ��
            if (j + 3 <= 7 && num[i][j] == num[i][j+1] && num[i][j] == num[i][j+2] && num[i][j] == num[i][j+3])
                return num[i][j];
            // б
            if (i + 3 <= 6 && j + 3 <= 7 && num[i][j] == num[i+1][j+1] && num[i][j] == num[i+2][j+2] && num[i][j] == num[i+3][j+3])
                return num[i][j];
            // б
            if (i + 3 <= 6 && j - 3 >= 1 && num[i][j] == num[i+1][j-1] && num[i][j] == num[i+2][j-2] && num[i][j] == num[i+3][j-3])
                return num[i][j];
        }
    }
    return 0;
}

bool tie() // �ж�ƽ��
{
    for (int j = 1; j <= 7; j++)
    {
        if (num[1][j] == 0) return false;
    }
    return true;
}

void drawBoard() // ��ӡ��ǰ���
{
    cout << "   ";
    for (int i = 1; i <= 7; i++) 
    {
        if (i == pos)
        {
			#ifdef _WINDOWS	
            	if (color == BLACK) cout << " ��";
            	else cout << " ��";
            #else
            	if (color == BLACK) cout << " ��  ";
            	else cout << " ��  ";
            #endif
        }
        else cout << "    ";
    }
    cout << "\n";
    // ����ϱ߿�
    cout << "  �X";
    for (int i = 1; i <= 6; i++) cout << "�T�T�T�h";
    cout << "�T�T�T�[\n";
    // ����м䲿��
    for (int i = 1; i <= 6; i++) // ��
    {
        cout << "  �U";
        for (int j = 1; j <= 7; j++) // ��
        {
            if (num[i][j] == BLACK)
            {
            	#ifdef _WINDOWS	
                	cout << " �� ";
                #else
                	cout << " �� ";
                #endif
            } 
            else if (num[i][j] == WHITE)
            {
            	#ifdef _WINDOWS	
                	cout << " �� ";
                #else
                	cout << " �� ";
                #endif
            }
            else cout << "   ";
            if (j != 7)
                cout << "��";
            else
                cout << "�U";
        }
        cout << " \n";
        // ����±߿�
        if (i != 6)
        {
            cout << "  �c";
            for (int i = 1; i <= 6; i++) cout << "��������";
            cout << "�������f\n";
        }
        else
        {
            cout << "  �^";
            for (int i = 1; i <= 6; i++) cout << "�T�T�T�k";
            cout << "�T�T�T�a\n";
        }
    }
}

// �� �������ɶ˵�3�� +500��
// �� һ�����ɶ˵�3�� +100��
// �� �������ɶ˵�2�� +100��
// �� һ�����ɶ˵�2�� +10��

namespace pipi
{
    int eval(int player) // ����player��ɫ��ǰ�ĵ÷�
    {
        int value = 0;
        // ������
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
                    if (num[i][j-1] == 0) free++; // ���
                    if (num[i][j+cnt] == 0) free++; // �Ҷ�
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    j += cnt;
                }
            }
        }
        // cout << value << endl;
        // ������
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
                    if (num[i-1][j] == 0) free++; // �϶�
                    if (num[i+cnt][j] == 0) free++; // �¶�
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    i += cnt;
                }
            }
        }
        // cout << value << endl;
        // ��������б�߼��
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j-1] == player) continue; // ֻ�жϵ�һ����
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j+cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j-1] == 0) free++; // ���϶�
                    if (num[i+cnt][j+cnt] == 0) free++; // ���¶�
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                }
            }
        }
        // cout << value << endl;
        // ��������б�߼��
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j+1] == player) continue; // ֻ�жϵ�һ����
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j-cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j+1] == 0) free++; // ���϶�
                    if (num[i+cnt][j-cnt] == 0) free++; // ���¶�
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
        if (findWinner() == player) // ��ʤ���������
            return INF;
        if (findWinner() == -1*player) // ʧ�ܣ�������С
            return -INF;
        if (step > maxD)
        {
            int ans = eval(player) - eval(-1*player);
            return ans;
        }
        int value[10] = {};
        if (step % 2 == 1) // max��󣬽�ɫplayer
        {
            int maxV = -1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // ����i��
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
        else // min��С����ɫ-1*player
        {
            int minV = 1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // ����i��
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
    int eval(int player) // ����player��ɫ��ǰ�ĵ÷�
    {
        int value = 0;
        // ������
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
                    if (num[i][j-1] == 0) free++; // ���
                    if (num[i][j+cnt] == 0) free++; // �Ҷ�
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    j += cnt;
                }
            }
        }
        // cout << value << endl;
        // ������
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
                    if (num[i-1][j] == 0) free++; // �϶�
                    if (num[i+cnt][j] == 0) free++; // �¶�
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                    i += cnt;
                }
            }
        }
        // cout << value << endl;
        // ��������б�߼��
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j-1] == player) continue; // ֻ�жϵ�һ����
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j+cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j-1] == 0) free++; // ���϶�
                    if (num[i+cnt][j+cnt] == 0) free++; // ���¶�
                    if (cnt == 3 && free == 2) value += 500;
                    if (cnt == 3 && free == 1) value += 100;
                    if (cnt == 2 && free == 2) value += 100;
                    if (cnt == 2 && free == 1) value += 10;
                }
            }
        }
        // cout << value << endl;
        // ��������б�߼��
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                int cnt = 0, free = 0;
                if (num[i-1][j+1] == player) continue; // ֻ�жϵ�һ����
                if (num[i][j] == player)
                {
                    while (num[i+cnt][j-cnt] == player)
                    {
                        cnt++;
                    }
                    if (num[i-1][j+1] == 0) free++; // ���϶�
                    if (num[i+cnt][j-cnt] == 0) free++; // ���¶�
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
        if (findWinner() == player) // ��ʤ���������
            return INF;
        if (findWinner() == -1*player) // ʧ�ܣ�������С
            return -INF;
        if (step > maxD)
        {
            int ans = eval(player) - eval(-1*player);
            return ans;
        }
        int value[10] = {};
        if (step % 2 == 1) // max��󣬽�ɫplayer
        {
            int maxV = -1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // ����i��
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
        else // min��С����ɫ-1*player
        {
            int minV = 1e9;
            for (int i = 1; i <= 7; i++)
            {
                if (num[1][i] == 0) // ����i��
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


int game() // ��ʼ��Ϸ
{
    clear();
    cout << "**********************************" << endl;
    cout << "�������������������� Ready Go�� ������������������������" << endl;
    cout << "**********************************" << endl;
    getch();

    char ch = 0;
    while (true) // ����Ϸû����ʱ
    {
        pos = pipi::strategy(BLACK);
        moveDown();
        clear();
        drawBoard(); // ��ӡ����
        int winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                cout << " �� ";
            } 
            else if (winner == WHITE)
            {
                cout << " �� ";
            }
            cout << "��ʤ" << endl;
            return winner;
        }
        if (tie()) // �ж�ƽ��
        {
            cout << "ƽ��" << endl;
            return 0;
        }

        // ����
        pos = pipi2::strategy(WHITE);
        moveDown();
        clear();
        drawBoard(); // ��ӡ����
        winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                cout << " �� ";
            } 
            else if (winner == WHITE)
            {
                cout << " �� ";
            }
            cout << "��ʤ" << endl;
            return winner;
        }
        if (tie()) // �ж�ƽ��
        {
            cout << "ƽ��" << endl;
            return 0;
        }
    }
}

int game2() // �������Ϸ
{
    // clear();
    // cout << "**********************************" << endl;
    // cout << "�������������������� Ready Go�� ������������������������" << endl;
    // cout << "**********************************" << endl;
    // getch();

    char ch = 0;
    while (true) // ����Ϸû����ʱ
    {
        pos = pipi::strategy(BLACK);
        moveDown();
        // clear();
        // drawBoard(); // ��ӡ����
        int winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                // cout << " �� ";
            } 
            else if (winner == WHITE)
            {
                // cout << " �� ";
            }
            // cout << "��ʤ" << endl;
            return winner;
        }
        if (tie()) // �ж�ƽ��
        {
            // cout << "ƽ��" << endl;
            return 0;
        }

        // ����
        pos = pipi2::strategy(WHITE);
        moveDown();
        // clear();
        // drawBoard(); // ��ӡ����
        winner = findWinner();
        if (winner != 0)
        {
            if (winner == BLACK)
            {
                // cout << " �� ";
            } 
            else if (winner == WHITE)
            {
                // cout << " �� ";
            }
            // cout << "��ʤ" << endl;
            return winner;
        }
        if (tie()) // �ж�ƽ��
        {
            // cout << "ƽ��" << endl;
            return 0;
        }
    }
}

void intro() // ��Ϸ����չʾ
{
    cout << "***********************************************************" << endl;
    cout << "��ӭ���� ������ ��Ϸ��" << endl;
    cout << "�������Ϸ�����һ�� 6*7 �ı��" << endl;
    cout << "����ѡ�� ������������ѡ��ĳһ��" << endl;
    cout << "�� ���»�б������������һ��ֱ�� ��Ϸ������" << endl; 
    cout << "�����ENTER����ʼ��Ϸ" << endl;
    cout << "�����ESC���˳���Ϸ" << endl;
    cout << "***********************************************************" << endl;
}

void init()
{
	srand(time(0));
	memset(num, 999999, sizeof(num));
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 7; j++)
            num[i][j] = 0;
	rd = 0; // �غ���
	pos = 1; // ������
	color = BLACK; // ����
}

int main()
{
    init();
    int cnta = 0, cntb = 0, cntc = 0; // ��ʤ ��ʤ ƽ��
    cout << "�밴�������ʼ��һ�غ�~" << endl;
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
        	cout << "��" << t << "�ֽ����" << " �� ��ʤ" << endl;
        else if (winner == -1)
        	cout << "��" << t << "�ֽ����" << " �� ��ʤ" << endl;
        else
        	cout << "��" << t << "�ֽ����" << "ƽ��" << endl;
    }
    cout << "��ʤ: " << cnta << endl;
    cout << "��ʤ: " << cntb << endl;
    cout << "ƽ��: " << cntc << endl;
    return 0;
}