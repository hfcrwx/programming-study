#ifndef _SHM_FIFO_H_
#define _SHM_FIFO_H_

#include "ipc.h"

typedef struct shmfifo shmfifo_t;
typedef struct shmhead shmhead_t;

struct shmhead
{
	unsigned int blksize;		// ���С
	unsigned int blocks;		// �ܿ���
	unsigned int rd_index;		// ������
	unsigned int wr_index;		// д����
};

struct shmfifo
{
	shmhead_t *p_shm;			// �����ڴ�ͷ��ָ��
	char *p_payload;			// ��Ч���ص���ʼ��ַ

	int shmid;					// �����ڴ�ID
	int sem_mutex;				// ���������õ��ź���
	int sem_full;				// �������ƹ����ڴ��Ƿ������ź���
	int sem_empty;				// �������ƹ����ڴ��Ƿ�յ��ź���
};

shmfifo_t* shmfifo_init(int key, int blksize, int blocks);
void shmfifo_put(shmfifo_t *fifo, const void *buf);
void shmfifo_get(shmfifo_t *fifo, void *buf);
void shmfifo_destroy(shmfifo_t *fifo);

#endif /* _SHM_FIFO_H_ */
