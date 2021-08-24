#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//ʵ�ּ�����

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

//��������ķ�����
//int main() {
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do {
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������������������>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("������������������>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("������������������>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("������������������>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("�˳���\n");
//			break;
//		default:
//			printf("�����������������룡����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//���պ����ĵ�ַ�����øú��� ���� �ص�����
void Calc(int (*pf)(int, int)) {
	int x = 0;
	int y = 0;
	printf("��������������>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}

int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	int(*pfArr[7])(int, int) = { 0,Add,Sub,Mul,Div,Exp,XOR };//����ָ������
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		if (input >= 1 && input <= 6) {
			printf("�������������>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0) {
			printf("�˳���\n");
		}
		else {
			printf("�������󣡣���\n");
		}
	} while (input);

	return 0;
}

//��������ĸĽ�������2��
//int main() {
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do {
//		menu();
//		printf("��ѡ��>");
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
//			printf("�˳���\n");
//			break;
//		default:
//			printf("�����������������룡����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}