#include <stdbool.h>
static int cuslist_now = 0;
static int cuslist_size = 0;
static char id[20];

typedef struct _Customer {

    char id[20];
    char password[20];
    char name[20];
    int reservation_detail[10][5];

}customer;

static char branches[13][20] = {"None", "Taipei Xinyi", "Taipei Fuxing", "Taipei Tienmu", "Taipei Taipei 101", "Taipei Nanxi", "Taipei A4" , "Taipei A13" , "Taipei Xinsheng" , "Taipei Banqiao" , "Hsinchu" , "Taichung" , "Kaohsiung" };
static int currentdate;
static int currenthour;
static int currentminute;
static int currentmonth;
static int currentyear;
static int currentday;
static int cuslist_m = 0;
static int datearray[7][4];
void login();
void register_();
bool check_id(char* id);
void afterlogin();
void make_reservation();
void reservation_enquiry();
void afterregister();
void datearrayspan();

bool loginidcheck(char* id);
bool registeridcheck(char* id);

static customer cuslist[100];


customer* logincheck_(customer* c, int* size, char* id, char* password);

customer* register_check_(customer* c, int* size, char* id, char* password);
