#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct KhachHang{
    char kh_name[100];
    int kh_id; 
    char kh_sdt[100];
};

// hàm khởi tạo khách hàng với tham số mặc định
void KhachHang_init(struct KhachHang *kh){
    kh->kh_id = 0;
    strcpy(kh->kh_name,"");
    strcpy(kh->kh_sdt,"");
}

// hàm khởi tạo khách hàng với tham số cụ thể
void KhachHang_init_params(struct KhachHang *kh, int kh_id, const char *kh_name, const char *kh_sdt) {
    kh->kh_id = kh_id;
    strncpy(kh->kh_name, kh_name, sizeof(kh->kh_name) - 1);
    strncpy(kh->kh_sdt, kh_sdt, sizeof(kh->kh_sdt) - 1);
}


 // hàm gán tên cho khách hàng

 void setkh_name(struct KhachHang *kh, const char *kh_name){
    strncpy(kh->kh_name, kh_name, sizeof(kh->kh_name)-1);// sao chéo kh_name đến trường kh->kh_name
 }

 //hàm lấy tên của khách hàng

const char* getkh_name(struct KhachHang *kh){
    return kh->kh_name;
}
//hàm gán id cho khách hàng
void setkh_id(struct KhachHang *kh,int kh_id){
    kh->kh_id= kh_id;
}

// hàm lấy giá trị id của khách hàng
 int getkh_id(struct KhachHang *kh){
    return kh->kh_id;
 }


//hàm gán số điện thoại cho khách hàng
void setkh_sdt(struct KhachHang *kh, const char* kh_sdt){
   strncpy(kh->kh_sdt, kh_sdt, sizeof(kh->kh_name)-1);
}

//hàm lấy số điện thoại cho khách hàng
const char* getkh_sdt(struct KhachHang *kh){
    return kh->kh_sdt;
}



//hàm ghi thông tin khách hàng

void saveKhachHang(struct KhachHang *kh, const char *filename){
    FILE *file=fopen(filename, "w");
    if(file==NULL){
        perror("Loi mo file");
        return;
    }
    fprintf(file," %d\n%s\n%s\n%d\n", kh->kh_id, kh->kh_name,  kh->kh_sdt );
    fclose(file);

}

// hàm đọc thông tin khách hàng

void loadKhachHang(struct KhachHang *kh, const char* filename){
    FILE *file=fopen(filename,"r");
    if(file==NULL){
        perror("Loi doc file");
        return;
    }
     fgets(kh->kh_name,100, file);
    kh->kh_name[strcspn(kh->kh_name,"\n")] = '\0';
    fscanf(file, "%d\n", &kh->kh_id);
    fgets(kh->kh_sdt,100, file);
    kh->kh_sdt[strcspn(kh->kh_sdt,"\n")] = '\0';
    fclose(file);
}


//hàm hiển thị thông tin khách hàng
void displayKhachHang(struct KhachHang *kh){
    printf("Ma khach hang: %d \n", kh->kh_id  );
    printf("Ten khach hang: %s\n ", kh->kh_name);
    printf("So dien thoai: %d \n", kh->kh_sdt);
}

// Date
struct Date{
    int day;
    int month;
    int year;
};

struct Date parseDate(const char* dateStr) {
    struct Date date;
    sscanf(dateStr, "%d/%d/%d", &date.day, &date.month, &date.year);
    return date;
}
void setdate_day(struct Date *d,int day){
	d->day= day;
}
int getdate_day(struct Date *d){
	return d->day;
}
void setdate_month(struct Date *d,int month){
	d->month= month;
}
int getdate_month(struct Date *d){
	return d->month;
}
void setdate_year(struct Date *d, int year){
	d->year= year;
}
int getdate_year(struct Date *d){
	return d->year;
}

      

// SẢN PHẨM

struct SanPham{
    int sp_id;
    char sp_name[100];
    double sp_price;
    int sp_nums;
     struct Date sp_date;
    char sp_donvi[50];

};

// hàm khởi tạo sản phẩm với tham số mặc định

void SanPham_init(struct SanPham *sp){
    sp->sp_id=0;
    strcpy(sp->sp_name,"");
    sp->sp_price=0.0;
    sp->sp_nums=0;
    sp->sp_date.day=0;
    sp->sp_date.month=0;
    sp->sp_date.year=0;
    strcpy(sp->sp_donvi,"");
}

// hàm khởi tạo với tham số cụ thể

void SanPham_init_params(struct SanPham *sp, int sp_id, const char *sp_name, double sp_price, int sp_nums, struct Date *d, const char* sp_donvi ){
     sp->sp_id = sp_id;
     strncpy(sp->sp_name,sp_name,sizeof(sp->sp_name)-1);
     sp->sp_price = sp_price;
     sp->sp_nums = sp_nums;
     sp->sp_date= *d;
     strncpy(sp->sp_donvi,sp_donvi,sizeof(sp->sp_donvi)-1);

}


//hàm hiển thị
void  displaySanPham(struct SanPham* sp) {
    printf("ID: %d\n", sp->sp_id);
    printf("Name: %s\n", sp->sp_name);
    printf("Price: %.2f\n", sp->sp_price);
    printf("Nums: %d\n", sp->sp_nums);
    printf("Donvi: %s\n", sp->sp_donvi);
}


// HÓA ĐƠN

 struct HoaDon {
    struct KhachHang kh;
    struct SanPham* sp;
    int seri;
    int stt;
    int sum;
    
} ;

// Khởi tạo

   struct HoaDon* HoaDon_init(struct KhachHang kh, struct SanPham* sp, int seri, int stt, double sum) {
    struct HoaDon* hd = (struct HoaDon*)malloc(sizeof(struct HoaDon));
    hd->kh = kh;
    hd->sp = (struct SanPham*)malloc(sizeof(struct SanPham) * stt);
    hd->seri = seri;
    hd->stt = stt;
    hd->sum = sum;
    
    return hd;
}

// Giải phóng bộ nhớ động
void HoaDon_free(struct HoaDon* hd) {
    free(hd);
}



// Phuong thuc them san pham
void HOADON_themsanpham(struct HoaDon* hd, struct SanPham sp) {
    int size = hd->stt;
    hd->sp = realloc(hd->sp, (size + 1) * sizeof(struct SanPham*));
    hd->sp[size] = sp;
    hd->stt++;
}

// Phuong thuc xoa san pham

void HOADON_xoasanpham(struct HoaDon* hd, int sp_id) {
    int size = hd->stt;
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (hd->sp[i].sp_id == sp_id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            hd->sp[i] = hd->sp[i + 1];
        }
        hd->sp = realloc(hd->sp, (size - 1) * sizeof(struct SanPham));
        hd->stt--;
    }
}

// Phuong thuc tinh tong so tien cho hoa don
double HOADON_tinhTongTien(struct HoaDon* hd) {
    double tongTien = 0;
    for (int i = 0; i < hd->stt; i++) {
        tongTien += hd->sp[i].sp_price * hd->sp[i].sp_nums;
    }
    return tongTien;
}

void NhapHoaDon(struct HoaDon *m, struct SanPham *kho,struct KhachHang *kh, struct Date *d, int kho_size) {
    char c = 'N';
    do {
        
        printf("\nXin moi nhap ID san pham: ");
        int product_id;
        scanf("%d", &product_id);
        struct SanPham product;
        int found = 0;
        for (int j = 0; j < kho_size; j++) {
            if (kho[j].sp_id == product_id) {
                product = kho[j];
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("San pham khong ton tai trong kho.\n");
            continue;
        }

        printf("\nSo luong: ");
        int a;
        scanf("%d", &a); 
        product.sp_nums = a;
        double cnt = product.sp_nums * product.sp_price;
        m->sum += cnt;
        HOADON_themsanpham(m, product);
        printf("\nBan co muon tiep tuc khong? Y/N: ");
        getchar(); // Clear the newline character
        c = getchar();
    } while (c == 'y' || c == 'Y');
  
    printf("\nNhap thong tin khach hang: ");
    printf("\nTen khach hang: ");
    getchar(); 
    fflush(stdin);
    fgets(kh->kh_name,100,stdin);
    kh->kh_name[strcspn(kh->kh_name, "\n")]= '\0';
    setkh_name( kh, kh->kh_name);
    printf("\nMa khach hang: ");
    scanf("%d", &kh->kh_id);
    setkh_id(kh,kh->kh_id);
    getchar();
    

    printf("\nSo dien thoai : ");
    fflush(stdin);
    fgets(kh->kh_sdt,100,stdin);
    kh->kh_sdt[strcspn(kh->kh_sdt, "\n")]= '\0';
    setkh_sdt( kh, kh->kh_sdt);
    

    printf("\nNhap thong tin hoa don: ");
    printf("\nNhap thoi gian: ");

    scanf("%d %d %d",&d->day,&d->month,&d->year);
    setdate_day(d,d->day);
    setdate_month(d,d->month);
    setdate_year(d,d->year);

}


void InHoaDon(struct HoaDon m, struct KhachHang *kh, struct Date *d) {   
    printf("\n\n\n\n");
    printf("\n                                  SUPERMARKET                          \n");
    printf("\nDia chi: So 1 Dai Co Viet, Hai Ba Trung, Ha Noi\n");
    printf("\nTen khach hang: %s", getkh_name(kh));
    printf("\nMa khach hang: %d", getkh_id(kh));
    printf("\nSo dien thoai: %s", getkh_sdt(kh));
    printf("\nThoi gian: %d/%d/%d \n\n", getdate_day(d), getdate_month(d), getdate_year(d));
    for(int i=0; i<90;i++){
        printf("%s", "-");
    }
    printf("\n%7s | %-25s | %-9s | %-15s | %-11s | %-11s\n",
           "MSSP", "Ten san pham", "Don vi", "So luong", "Don gia", "Thanh tien");
    for (int j = 0; j < m.stt ; j++) {
        printf("%7d | %-25s | %-9s | %-15d | %-11.0f | %-11.0f\n",
               m.sp[j].sp_id,
               m.sp[j].sp_name,
               m.sp[j].sp_donvi,
               m.sp[j].sp_nums,
               m.sp[j].sp_price,
               m.sp[j].sp_nums * m.sp[j].sp_price);
    }
    for(int i=0; i<90;i++){
        printf("%s", "-");
    }
    printf("\nTong tien: %75.0f\n", (double)m.sum);
    printf("\n                            Hen gap lai quy khach!                     \n");
}




// Hàm đọc tệp CSV và lưu trữ thông tin sản phẩm
void readCSV(const char* filename,struct SanPham products[], int* count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open the file");
        return;
    }

    char line[256];
    // Bỏ qua dòng tiêu đề
    fgets(line, sizeof(line), file);
    
    int index = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        strncpy(products[index].sp_name, token, sizeof(products[index].sp_name) - 1);

        token = strtok(NULL, ",");
        products[index].sp_id = atoi(token);

        token = strtok(NULL, ",");
        products[index].sp_price = atof(token);

        token = strtok(NULL, ",");
        products[index].sp_nums = atoi(token);

        token = strtok(NULL, ",");
        products[index].sp_date = parseDate(token);

        token = strtok(NULL, ",");
        strncpy(products[index].sp_donvi, token, sizeof(products[index].sp_donvi) - 1);

        index++;
    }
    *count = index;

    fclose(file);
}

void checkInventory(struct SanPham* products, int count) {
    int id;
    printf("Hay nhap ID san pham can tim: ");
    scanf("%d", &id);
    getchar();  // Đọc ký tự newline còn lại trong bộ đệm

    for (int i = 0; i < count; i++) {
        if (products[i].sp_id == id) {
            printf("Thong tin san pham:\n");
            displaySanPham(&products[i]);
            return;
        }
    }
    printf("San pham voi ID %d khong ton tai.\n", id);
}

int main(){
     struct SanPham kho[100];
    int kho_count = 0;
    readCSV("mini_supermarket_products_en.txt", kho, &kho_count);

    int seri = 12345678;
    int i=0;
    struct HoaDon* m = HoaDon_init((struct KhachHang){0}, NULL, seri, 0, 0.0);
    int choice;
    struct KhachHang kh;
    struct Date d;

    while (1) {
        printf("Vui long chon mot tuy chon:\n");
        printf("1. In hoa don\n");
        printf("2. Kiem tra kho hang\n");
        printf("3. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character
        switch (choice) {
            case 1:
                NhapHoaDon(m, kho, &kh, &d, kho_count);
                InHoaDon(*m, &kh,&d);
                break;
            case 2:
                checkInventory(kho, kho_count);
                break;
            case 3:
                printf("Thoat chuong trinh. Cam on!\n");
                HoaDon_free(m);
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
        printf("\n");
    }

    return 0;
}





