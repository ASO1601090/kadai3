/************************************************/
/*  ido.c
/*
/*  ���͒l����O�p�֐����g�p����
/*  �ړI�n��x,y���W�ŕ\���B
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
/*  �p�����[�^ : �Ȃ�
/*  �߂�l     : �Ȃ�
/*
/*  �O�p�֐����g���A�ʒu�v�Z����B
/************************************************/

void main(void)
{
    double root;          /* �Εӂ̕����� */
    double ac;            /* �t�O�p�֐�(�t�]��) */
    double c;             /* �O�p�֐�(�]��) */
    double s;             /* �O�p�֐�(����) */
    double kakudo;        /* �p�x */
    double sum = 0;       /* �p�x���v */
    double teata;         /* �ŏI�p�x */
    float x ,y;           /* ���߂�n�_ */
    float gyou;           /* �s�� */
    int i;                /* �J�E���g�p�ϐ� */
    int syogen;           /* �ی��p�ϐ� */

    gyou = input();       /* �s������ */

    for(i=2;i<=gyou;i++){                           /* �Q�s�ڂ���P�s�����p�x�𑫂����� */

        root = sqrt(i);                             /* �s�ԍ��̕����������߂�(�Εӂ̒����ɂȂ�) */
        ac = acos(1/root);                          /* �Εӂƒ�ӂ��g���ċt�]�����v�Z(�p�x�̌v�Z) */
        kakudo = 180 - (90 + ac * 180 / M_PI);      /* ���W�A�����u�x�v�ɕϊ����A���߂����p�x���Z�o */

        sum = sum + kakudo;                         /* �p�x���v�p�̕ϐ��ɑ������� */

    }

    teata = sum;


    while(teata > 360){                             /* �~�Ȃ̂ōŏ��̑傫�������߂� */
        teata = teata - 360;
    }

    sum = sum * M_PI / 180;                         /* ���� �]�����v�Z���邽�߁u�x�v�����W�A���ɕϊ� */

    c = cos(sum);                                   /* �������v�Z */
    s = sin(sum);                                   /* �]�����v�Z */

    y = root * s;                                   /* ������p����y���W���Z�o */
	x = -(root * c);                                   /* �]����p����x���W���Z�o */    

    output(x, y);                                   /* ���ʂ�\�� */
    for(;;);                                        /* �i�v���[�v */

}


/************************************************/
/*  input
/*
/*  �p�����[�^ : �Ȃ�
/*  �߂�l     : float gyou [OUT]
/*
/*  ���͒l���������l���ǂ������ׂ�B
/************************************************/

float input(void)
{
  /* ��������� */
    char work[5];                                                   /* ���͒l�i�[�p�ϐ� */
    int flg = 0;                                                    /* ���[�v�p�ϐ� */
    float gyou;                                                     /* �ϊ����l�i�[�p�ϐ� */

    while( flg == 0 ) {

        flg = 1;
        printf("�s��(2�`1000)����͂��Ă������� = ");
        scanf("%s",work);

        if( strlen( work ) > 4 ) {	                                /* �G���[(���͕���4�����ȉ�����Ȃ�) */
            printf( "\n���̓~�X�ł�\n" );
            flg = 0;
        }

        if( strspn( work, "1234567890" ) < strlen( work ) ) {
            printf( "\n���l�ȊO�����͂���܂���\n" );
            flg = 0;
        }
        gyou = atoi(work);

        if(gyou == 1){
            flg = 0;                                                /* 2�ȏ�Ȃ̂Ń��[�v�p�� */
        }

    }

    return gyou;
}

/************************************************/
/*  output
/*
/*  �p�����[�^ : float x, y
/*  �߂�l     : �Ȃ�
/*
/*  ������W���o�͑��u�ɏo�́B
/************************************************/

void output(float x, float y)
{

    printf( "( %lf, %lf)", x, y);        /* �\�� */

}

