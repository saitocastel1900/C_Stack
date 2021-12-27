//2023178 齋藤亮磨　12月25日
//基本情報技術者試験にて出題されるデータ構造のスタック(FIFO) を、高級言語ベースで理解するためにシステムを構築しました(関数と変数の命令規則はローワーキャメルケースに従いました)。   
#include <stdio.h>
void initStack(struct STACK* stack);
void PUSH(struct STACK* stack, int num);
void POP(struct STACK* stack);
void stackPrint(struct STACK* stack);

//構造体tの定義
//配列の最後尾の要素番号
//データを格納するスタック
struct STACK
{
	int lastArray;
	int data[10];
}; 

//スタックの初期化
void initStack(struct STACK *stack) {

	//データが入力されている最後尾の要素番号を最初は-1で設定する(set)
	stack->lastArray = -1;
}

//PUSH（数値を代入）
void PUSH(struct STACK* stack, int num) {

	//入力されている値が要素数を超えていた場合は、メニューに戻す
	if (stack->lastArray>= 10) {
		printf("\t10個以上値が入力されているため、「PUSH(入力)することが出来ません。2:POP(出力)、3:現在のスタックを表示または4:スタックの終了」を選択してください。申し訳ありません。");
		return;
	}

	//スタックに入力された値を格納する(格納すると同時に配列の最後尾の番号を変更する)
	stack->data[stack->lastArray +1]=num;
	stack->lastArray = stack->lastArray + 1;
}

//POP(数値を出力)
void  POP(struct STACK *stack) {

	int resultValue = 0;

	//最後尾の要素の番号が-1だったら(何も入力されていなかったら)...
	if (stack ->lastArray ==-1) {
		printf("\tスタックが空であるため出力できる数値がありません。\n\t数値を入力してから出力するようにしてください\n");
		return-1;
	}

	//最近代入された値を出力する
	resultValue = stack->data[stack->lastArray];
	stack->lastArray = stack->lastArray - 1;
	printf("\t:%d",resultValue);
}

//スタックの中身を表示
void stackPrint(struct STACK *stack){

	if (stack->lastArray ==-1)printf("\tスタックに何も入力されていないため、何も表示できません\n");

	for (int i = 0; i<=stack->lastArray; i++) {
		printf("\t  \n\t|%d|\n\t  ",stack->data[stack->lastArray -i]);
	}
}

int main() {

	//入力される値を格納する変数,booleanを使わずに整数型でスタックを続けるか判断する変数
	int num=0,flag=0;

	//使用する構造体の定義
	struct STACK stack[10];

	printf("\tスタックをします\n\t入力は整数のみ受け付けます\n");

	initStack(&stack);

	do
	{
		printf("\n");
		printf("\tメニュー\n\t1:PUSH(入力)\n\t2:POP(出力)\n\t3:現在のスタックの状況を表示\n\t4:スタックを終了(終了後にスタックの状況を表示します)\n");
		printf("\t:");
		scanf("%d",&flag);

		switch (flag)
		{
			//整数を入力(PUSH)
		case 1:
			printf("\t---------------\n");
			printf("\t整数をPUSHします。値を入力してください:");
			scanf("%d",&num);
			PUSH(&stack,num);
			break;

			//スタックに最近積み上げられた値を出力(POP)
		case 2:
			printf("\t---------------\n");
			printf("\t最近入力された値をPOPします\n");
			POP(&stack);
			break;

			//スタックの中身を表示する
		case 3:
			printf("\t---------------\n");
			printf("\t現在のスタックの中身を表示します\n");
			stackPrint(&stack);
			break;

			//スタックの処理を終了する
		case 4:
			printf("\t---------------\n");
			printf("\tスタックを終了します\n\t本当に終了しますか？\n\t1:終了しない	4:終了する\n");
			puts(":");
			scanf("%d",&flag);
			//
			if (flag==1) {
				flag =1;
			}
			else if(flag==4)
			{
				flag =4;

				//スタック処理の完全終了
				printf("\t---------------\n");
				printf("\tスタック終了\n");
				stackPrint(&stack);
				printf("\tご利用ありがとうございました！");
			}
			break;

			//想定外の値が入力されていた時の処理
		default:
			printf("\t1~4以外の数値が入力されています。スタックをやめる場合は4を入力していください\n");
			break;
		}

	} while (flag==1||flag == 2||flag == 3) ;

	return 0;
}
/*
		スタックをします
		入力は整数のみ受け付けます

		メニュー
		1:PUSH(入力)
		2:POP(出力)
		3:現在のスタックの状況を表示
		4:スタックを終了(終了後にスタックの状況を表示します)
		:1
		---------------
		整数をPUSHします。値を入力してください:1

		メニュー
		1:PUSH(入力)
		2:POP(出力)
		3:現在のスタックの状況を表示
		4:スタックを終了(終了後にスタックの状況を表示します)
		:3
		---------------
		現在のスタックの中身を表示します

		|1|

		メニュー
		1:PUSH(入力)
		2:POP(出力)
		3:現在のスタックの状況を表示
		4:スタックを終了(終了後にスタックの状況を表示します)
		:4
		---------------
		スタックを終了します
		本当に終了しますか？
		1:終了しない    4:終了する
1

		メニュー
		1:PUSH(入力)
		2:POP(出力)
		3:現在のスタックの状況を表示
		4:スタックを終了(終了後にスタックの状況を表示します)
		:4
		---------------
		スタックを終了します
		本当に終了しますか？
		1:終了しない    4:終了する
4
		---------------
		スタック終了

		|1|
				ご利用ありがとうございました！
*/
//考察
//今回構築したプログラムは、基本情報技術者試験にて出題されるスタックの機能を実装したものである。実際に基本情報技術者試験にて出題される試験問題に準拠して、入出力をPOPやPUSHにした。
//問題点として、配列の要素数があらかじめ定まっている点が問題であると感じた。このコードの場合10件以上の入力の場合は受付ないように設定して対処しているが、ユーザにとっては不親切と感じざるを得ないと考える。この問題を改善するには、ポインタと構造体を用いたリンク構造体（共用体）を導入するすればC#におけるList<>の様に後から要素数を考える必要なく数値を入れることが出来ると考える。春休みの際に、実装したいと考えている。
//それ以外の問題点として、配列がint型であるため、スタックは整数型しか対応しておらず、それ以外の値のも対応する必要があると考える。