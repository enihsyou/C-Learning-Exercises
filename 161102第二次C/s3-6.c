#include <stdio.h>
main() {
    float a, b;
    int i, f = 0;
    printf("������������ʱ���ֻ���ʵ�ʼ۸�\n");
    scanf("%f", &b);
    system("cls");
    for (i = 1; i <= 3; i++) {
        printf("\n\n����ڲ�ʱ���ֻ��ļ۸�\n");
        scanf("%f", &a);
        if(a < b) printf("����\n");
        if(a == b) {
            printf("�¶���!\n");
            f = 1;
            break;
        }
        if(a > b) printf("����\n");
    }
    if(f != 1)printf("�����ˣ����ͣ�\n");
    system("pause");
}
