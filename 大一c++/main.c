/*Made By Youngsc*/

# include <windows.h>
# include <conio.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <windows.h>
# include <mmsystem.h>

int n, mid = 100, dif, opt, flag, score ,Eatsum ,mapID;
int bx[] = { 0,-1,1,0,0 }, by[] = { 0,0,0,-1,1 };
char s[55];

struct hh{
	int x,y,p,end;
	struct hh *pre,*next;
}che[110][110],*head;

void HideCursor(){
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void gotoxy(int y, int x) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	HideCursor();
}

void music()
{
    PlaySound(TEXT(".\\aa.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void color(int a) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	/*
	��
	1 	����ɫ
	2 	����ɫ
	3 	����ɫ
	4 	���ɫ
	5 	���ɫ
	6	���ɫ
	7 	���ɫ
	8 	��ɫ
	9 	ǳ��ɫ
	10 	ǳ��ɫ
	11 	ǳ��ɫ
	12	ǳ��ɫ
	13	ǳ��ɫ
	14	ǳ��ɫ
	15	ǳ��ɫ


	����
	1~15		��ɫ
	16~31		����ɫ
	32~47		����ɫ
	48~63		����ɫ
	64~79		���ɫ
	80~95		���ɫ
	96~111		���ɫ
	112~127 	���ɫ
	128~143 	��ɫ
	144~159 	ǳ��ɫ
	160~175 	ǳ��ɫ
	176~191 	ǳ��ɫ
	192~207 	ǳ��ɫ
	208~223 	ǳ��ɫ
	224~239 	ǳ��ɫ
	240~255 	ǳ��ɫ
	*/
}

int Get() {
	int res = 0;
	char ch;
	do {
		ch = _getch();
		switch (ch) {
		case 72: res = 1; break;
		case 80: res = 2; break;
		case 75: res = 3; break;
		case 77: res = 4; break;
		default: break;
		}
	} while (!res);
	return res;
}

void Out() {
	system("cls");
	for (int i = 0; i <= n+1; i++)
	{
		color(10);
		for (int j = 0; j <= n+1; j++)
		{

			switch(che[i][j].p)
			{
				case 1: color(10); printf("��"); break;
				case 2: color(4);  printf("��"); break;
				case 3: color(12); printf("��"); break;
				case 4: color(4);  printf("��"); break;
				case 5: color(10); printf("��"); break;
			}
		}

		puts("");
	}
	puts("");
	printf("Your score : %d\n", score);
}

void Food() {
	int x, y;
	do {
		x = rand() % 13 + 1;
		y = rand() % 13 + 1;
	} while (che[x][y].p != 1);
	che[x][y].p = 3;
	gotoxy(x,y*2);
	color(12);
	printf("��");
	return;
}

void make1(){
	puts("�������ͼ�ı߳�:");
	puts("����Ҫ����40�������Ļ�Ų��£�");
	scanf("%d", &n);
	system("cls");

	puts("����һ������(1~10)���趨��Ϸ�Ѷ�.");
	puts("����Խ���ٶ�Խ��");
	scanf("%d", &dif);
	while (dif<1||dif>10) printf("�����뷶Χ�ڵ��Ѷ�ֵ\n"),scanf("%d",&dif);
	system("cls");
	mid *= dif;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			che[i][j].p=1;
			che[i][j].x=i;
			che[i][j].y=j;
		}

	for (int i=0; i<=n+1; ++i) che[0][i].p = che[i][0].p = che[n+1][i].p = che[i][n+1].p = 5;
}

void make2(){
	n = 13;
	char mapname[15]={0};
	puts("���������8�ŵ�ͼ����������Ҫ�ڼ���:");
	scanf("%d",&mapID);
	while (mapID<1||mapID>8) printf("�����뷶Χ�ڵĵ�ͼ���\n"),scanf("%d",&mapID);
	system("cls");

	puts("����һ������(1~10)���趨��Ϸ�Ѷ�.");
	puts("����Խ���ٶ�Խ��");
	scanf("%d", &dif);
	while (dif<1||dif>10) printf("�����뷶Χ�ڵ��Ѷ�ֵ\n"),scanf("%d",&dif);
	system("cls");
	mid *= dif;

	sprintf(mapname,"map%d.txt",mapID);
	freopen(mapname,"r",stdin);
	for (int i=0; i<=14; ++i)
		for (int j=0; j<=14; ++j)
			scanf("%d",&che[i][j].p),
			che[i][j].x = i,
			che[i][j].y = j;
	fclose(stdin);
}

void Be() {
	if (opt == 1) make1();
	else make2();

	int x,y;
	do {
		x = rand() % n + 1,
		y = rand() % n + 1;
	} while(che[x][y].p != 1);
	che[x][y].p = 2;
	che[x][y].end = 1;
	head = &che[x][y];
	flag = rand() % 4 + 1;
	do {
		x = head->x + bx[flag];
		y = head->y + by[flag];
		if (che[x][y].p == 1||che[x][y].p == 3) break;
		flag = (flag + 1) % 4;
		if (!flag) flag = 1;
	} while (1);

	Food();
	Out();
}

int Hashlist[1000010];

struct playersdata{
	int map[10];
	int relax;
	char name[55];
}playersmark[60];

unsigned int BKDRHash(char *str){
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash%1000007);
}

struct playersdata a[60];

void mysort1(int l,int r){
	if(l == r) return ;
	int m = (l+r)/2;
	mysort1(l,m), mysort1(m+1,r);
	int fa = l,fb = m+1,t = l-1;

	while(fa <= m&&fb <= r)
		if(playersmark[fa].relax > playersmark[fb].relax) a[++t] = playersmark[fa++];
		else a[++t] = playersmark[fb++];

	while(fa <= m) a[++t] = playersmark[fa++];
	while(fb <= r) a[++t] = playersmark[fb++];

	for(int i = l;i <= r;++i) playersmark[i] = a[i];
}

void mysort2(int l,int r,int mapID){
	if(l == r) return ;
	int m = (l+r)/2;
	mysort2(l,m,mapID), mysort2(m+1,r,mapID);
	int fa = l,fb = m+1,t = l-1;

	while(fa <= m&&fb <= r)
		if(playersmark[fa].map[mapID] > playersmark[fb].map[mapID]) a[++t] = playersmark[fa++];
		else a[++t] = playersmark[fb++];

	while(fa <= m) a[++t] = playersmark[fa++];
	while(fb <= r) a[++t] = playersmark[fb++];

	for(int i = l;i <= r;++i) playersmark[i] = a[i];
}

void print_rank(){
	int playersum,hashnum = BKDRHash(s);
	char playername[55]={0};
	freopen("players.txt","r",stdin);
	scanf("%d",&playersum);
	for (int i=1; i<=playersum; ++i)
	{
		scanf("%s",playername);
		int Hashn = BKDRHash(playername);
		Hashlist[Hashn] = i;
		memcpy(playersmark[i].name,playername,sizeof(playername));
		scanf("%d",&playersmark[i].relax);
		for (int j=1; j<=8; ++j) scanf("%d",&playersmark[i].map[j]);
	}
	fclose(stdin);
	int Hashn = BKDRHash(s), ID;
	if (!Hashlist[Hashn]) Hashlist[Hashn] = ++playersum;
	ID = Hashlist[Hashn];
	if (opt == 1) playersmark[ID].relax = score>playersmark[ID].relax? score:playersmark[ID].relax;
	else playersmark[ID].map[mapID] = score>playersmark[ID].map[mapID]? score:playersmark[ID].map[mapID];
	memcpy(playersmark[ID].name,s,sizeof(s));
	if (opt == 1) mysort1(1,playersum);
	else mysort2(1,playersum,mapID);
	printf("����Ϊ��ģʽ�¸õ�ͼ�����������ߵ÷����а�\n");
	printf("------ս����------\n");
	printf("       score    ID\n");
	for (int i=1; i<=playersum; ++i)
		printf("NO.%2d   %3d     %s\n",i, opt == 1? playersmark[i].relax:playersmark[i].map[mapID],playersmark[i].name);

	freopen("players.txt","w",stdout);
	printf("%d\n",playersum);
	for (int i=1; i<=playersum; ++i)
	{
		printf("%s\n%d ",playersmark[i].name,playersmark[i].relax);
		for (int j=1; j<=8; ++j) printf("%d ",playersmark[i].map[j]);
		printf("\n");
	}
	fclose(stdout);
}

void is_fail(int x, int y) {
	if (che[x][y].p != 1 && che[x][y].p != 3) {
		gotoxy(n+4,0);
		color(15);
		puts("Emnnnnnn......");
		puts("������˼������ˡ�����");
		print_rank();
		char c;
		while (c = getchar() && c != 'q');
		exit(0);
	}
	return;
}

void Eat(int x, int y) {
	score += 10 - dif + 1;
	Eatsum++;
	gotoxy(n+3,13);
	printf("%d         \n",score);
	che[x][y].p = 2;
	gotoxy(x,y*2);
	color(4);
	printf("��");
	head->p = 4;
	gotoxy(head->x,head->y*2);
	color(4);
	printf("��");
	head->next = &che[x][y];
	che[x][y].pre = head;
	head = &che[x][y];
	Food();
}

void Go(int x) {
	struct hh *to;
	to = &che[head->x+bx[x]][head->y+by[x]];
	is_fail(to->x,to->y);
	if (to->p == 3) Eat(to->x, to->y);
	else {
		head->next = to;
		to->pre = head;
		head->p = 4;
		gotoxy(head->x,head->y*2);
		color(4);
		printf("��");
		to->p = 2;
		gotoxy(to->x,to->y*2);
		color(4);
		printf("��");
		head = to;
		while (!to->end) {
			struct hh *now = to->pre;
			if (now->end) {
				now->p = 1;
				gotoxy(now->x,now->y*2);
				color(10);
				printf("��");
				now->end = 0;
				to->end = 1;
				break;
			}
			to = now;
		}
	}
	return;
}

void Move() {
	double l = clock();
	int tim = 1;
	while ((tim = (clock() - l < mid)) && !_kbhit());
	if (!tim) {
		Go(flag);
		return;
	}

	int want = Get();
	if (want == 1 && flag == 2) return;
	if (want == 2 && flag == 1) return;
	if (want == 3 && flag == 4) return;
	if (want == 4 && flag == 3) return;
	flag = want;
	Go(flag);
	return;
}

int main(){
	music();
	srand(time(0));

	printf("�봴�����ID�����Ѵ���������������ID\n���Ȳ�����50\n");
	scanf("%s",s);
	system("cls");
	printf("��ѡ����Ϸģʽ\n 1������ģʽ\n 2���ֻ�ģʽ\n(����1��2����س�����)\n");
	scanf("%d",&opt);
	while (opt != 1&&opt != 2) printf("������1��2\n"),scanf("%d",&opt);
	system("cls");

	Be();

	while (1) Move();

	return 0;
}


