#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//实现计算器

void menu() {
	printf("*****************************************************\n");
	printf("*******************    1. add    ********************\n");
	printf("*******************    2. sub    ********************\n");
	printf("*******************    3. mul    ********************\n");
	printf("*******************    4. div    ********************\n");
	printf("*******************    5. exp    ********************\n");
	printf("*******************    6. xor    ********************\n");
	printf("*******************    0. exit   ********************\n");
	printf("*****************************************************\n");
}

int Add(int x, int y) {
	return x + y;
}

int Sub(int x, int y) {
	return x - y;
}

int Mul(int x, int y) {
	return x * y;
}

int Div(int x, int y) {
	return x / y;
}

int Exp(int x, int y) {
	return pow(x, y);
}

int XOR(int x, int y) {
	return x ^ y;
}

//繁杂冗余的方法：
//int main() {
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do {
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入两个操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("退出！\n");
//			break;
//		default:
//			printf("输入有误，请重新输入！！！\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//接收函数的地址，调用该函数 —— 回调函数
void Calc(int (*pf)(int, int)) {
	int x = 0;
	int y = 0;
	printf("请输入两个数：>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}

int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	int(*pfArr[7])(int, int) = { 0,Add,Sub,Mul,Div,Exp,XOR };//函数指针数组
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		if (input >= 1 && input <= 6) {
			printf("请输入操作数：>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0) {
			printf("退出！\n");
		}
		else {
			printf("输入有误！！！\n");
		}
	} while (input);

	return 0;
}

//关于冗余的改进，方法2：
//int main() {
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do {
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//      case 5:
//          Calc(Exp);
//      case 6:
//          Calc(XOR);
//		case 0:
//			printf("退出！\n");
//			break;
//		default:
//			printf("输入有误，请重新输入！！！\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}