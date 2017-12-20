/************************************************/
/*  ido.c
/*
/*  入力値から三角関数を使用して
/*  目的地をx,y座標で表す。
/************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "ido.h"

float input( void );
void output( float x, float y);

/************************************************/
/*  main
/*
/*  パラメータ : なし
/*  戻り値     : なし
/*
/*  三角関数を使い、位置計算する。
/************************************************/

void main(void)
{
    double root;          /* 斜辺の平方根 */
    double ac;            /* 逆三角関数(逆余弦) */
    double c;             /* 三角関数(余弦) */
    double s;             /* 三角関数(正弦) */
    double kakudo;        /* 角度 */
    double sum = 0;       /* 角度合計 */
    double teata;         /* 最終角度 */
    float x ,y;           /* 求める地点 */
    float gyou;           /* 行数 */
    int i;                /* カウント用変数 */
    int syogen;           /* 象限用変数 */

    gyou = input();       /* 行数入力 */

    for(i=2;i<=gyou;i++){                           /* ２行目から１行分ずつ角度を足し込む */

        root = sqrt(i);                             /* 行番号の平方根を求める(斜辺の長さになる) */
        ac = acos(1/root);                          /* 斜辺と底辺を使って逆余弦を計算(角度の計算) */
        kakudo = 180 - (90 + ac * 180 / M_PI);      /* ラジアンを「度」に変換し、求めたい角度を算出 */

        sum = sum + kakudo;                         /* 角度合計用の変数に足しこむ */

    }

    teata = sum;


    while(teata > 360){                             /* 円なので最小の大きさを求める */
        teata = teata - 360;
    }

    sum = sum * M_PI / 180;                         /* 正弦 余弦を計算するため「度」をラジアンに変換 */

    c = cos(sum);                                   /* 正弦を計算 */
    s = sin(sum);                                   /* 余弦を計算 */

    y = root * s;                                   /* 正弦を用いてy座標を算出 */
	x = -(root * c);                                   /* 余弦を用いてx座標を算出 */    

    output(x, y);                                   /* 結果を表示 */
    for(;;);                                        /* 永久ループ */

}


/************************************************/
/*  input
/*
/*  パラメータ : なし
/*  戻り値     : float gyou [OUT]
/*
/*  入力値が正しい値かどうか調べる。
/************************************************/

float input(void)
{
  /* 文字を入力 */
    char work[5];                                                   /* 入力値格納用変数 */
    int flg = 0;                                                    /* ループ用変数 */
    float gyou;                                                     /* 変換数値格納用変数 */

    while( flg == 0 ) {

        flg = 1;
        printf("行数(2～1000)を入力してください = ");
        scanf("%s",work);

        if( strlen( work ) > 4 ) {	                                /* エラー(入力文字4文字以下じゃない) */
            printf( "\n入力ミスです\n" );
            flg = 0;
        }

        if( strspn( work, "1234567890" ) < strlen( work ) ) {
            printf( "\n数値以外が入力されました\n" );
            flg = 0;
        }
        gyou = atoi(work);

        if(gyou == 1){
            flg = 0;                                                /* 2以上なのでループ継続 */
        }

    }

    return gyou;
}

/************************************************/
/*  output
/*
/*  パラメータ : float x, y
/*  戻り値     : なし
/*
/*  引数を標準出力装置に出力。
/************************************************/

void output(float x, float y)
{

    printf( "( %lf, %lf)", x, y);        /* 表示 */

}

