#include <iostream>

using namespace std;

#define MAXQUEUE 3

typedef struct {
    int front;
    int rear;
    int count;
    int item[MAXQUEUE];
} queue;

queue antrian;

void inisialisasi(queue *q){
    q -> rear = 0;
    q -> front = 0;
    q -> count = 0;
}

int isEmpty(queue *q){
    int hasil = 0;
    if (q -> count == 0){
        hasil = 1;
    }
    return hasil;
}

int isFull(queue *q){
    int hasil = 0;
    if (q->count == MAXQUEUE){
        hasil = 1;
    }
    return hasil;
}

void insert(queue *q, int data){
    if(isFull(q) == 1){
        cout << "antrian penuh" << endl;
    } else {
        q -> item[q -> rear] = data;
        q -> rear = (q -> rear + 1) % MAXQUEUE;
        ++(q -> count);
        cout << "masukkan " << data << endl;
    }
}

void hapus(queue *q){
    if(isEmpty(q) == 1){
        cout << "Antrean Kosong " << endl;
    } else {
        cout << "Menghapus " << q -> item[q -> front] << " dari antrean" << endl;
        q -> front = (q -> front + 1) % MAXQUEUE;
        --(q -> count);
    }
}

void printqueue(queue *q){
    for(int i = 0; i < q -> count; i++){
        for(int j = 0; j <= i; j++){
            q -> item[(q -> front + j) % MAXQUEUE] ;
        }
        cout << endl;
    }

}

int main(){
    queue q;
    inisialisasi(&q);

    insert(&q, 17);
    cout << "Isi antrean: " << q.item[q.front] << endl;
    insert(&q, 45);
    cout << "Isi antrean: " << q.item[q.front] << " " << q.item[(q.front + 1)% MAXQUEUE] << endl;
    insert(&q, 77);
    cout << "Isi antrean: " << q.item[q.front] << " " << q.item[(q.front + 1)% MAXQUEUE] << " " << q.item[(q.front + 2)% MAXQUEUE] << endl;
    hapus(&q);
    insert(&q, 15);
    cout << "Isi antrean: " << q.item[q.front] << " " << q.item[(q.front + 1)% MAXQUEUE] << " " << q.item[(q.front + 2)% MAXQUEUE] << endl;
    printqueue(&q);

    return 0;
}