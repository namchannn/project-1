#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Struct: là cách duy nhất nói về 1 đối tượng mà trên đối tượng đó có các kiểu dữ liệu khác nhau */
// Viết chương trình QLNV với các chức năng:
// 1. Tìm kiếm
// 2. Hiển thị thông tin
// 3. Lương > 3000

#define MAX_EMPLOYEES 5 // Định nghĩa biến giới hạn slnv

// Hàm cấu trúc NV
struct employee{
	int eid; // Biến thành phần Mã NV
	char name[50]; // Biến thành phần tên NV
	float salary; // Biến cấu trúc lương NV
}emp[5];

// Hàm kiểm tra ID trùng nhau
bool checkSameId(struct employee emp[], int id,int currentEmployeeIndex){
	for(int i = 0; i < currentEmployeeIndex; i++){
		if(emp[i].eid == id){
			return false; // nếu ID trùng trả về sai
		}
	}
	return true; // ID k trùng trả về đúng
}

// Hàm nhập thông tin Nviên
void creatEmployee(struct employee emp[]){
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		printf("Enter Employee %d:\n", i + 1);
		
		while(true){
			printf("Enter ID: ");
			scanf("%d", &emp[i].eid);
			
			if(checkSameId(emp, emp[i].eid, i)){ // thỏa mãn điều kiện check thì kết thúc vòng lặp
				break;
			}else{
				printf("ID already exists! Please try again.\n"); // không thỏa mãn thì báo lỗi yêu cầu nhập lại
			}
		}
		
		printf("Enter Name: ");
		fflush(stdin);
		gets(emp[i].name);
		printf("Enter Salary: ");
		scanf("%f", &emp[i].salary);
	}
}

// Hàm hiển thị thông tin tất cả NV
void displayAll(struct employee emp[]){
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		printf("Employee ID: %d", emp[i].eid);
		printf("\nName: ");
		puts(emp[i].name);
		printf("Salary: %0.2f$\n", emp[i].salary);
	}
}

// Hàm tìm kiếm thông tin NV theo ID
void findEmployeeById(struct employee emp[], int id){
	int found = 0;
	printf("\nResult Check\n");
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		if(emp[i].eid == id){
			found = 1;
			printf("Employee ID: %d", emp[i].eid);
			printf("\nName: ");
			puts(emp[i].name);
			printf("Salary: %0.2f$\n", emp[i].salary);
			break;
		}
	}
	if(!found){
		printf("ID not invalid! Please try again.\n");
	}
}

// Hàm tìm kiếm thông tin NV theo tên
void findEmployeeByName(struct employee emp[], char name[]){
	int found = 0;
	printf("\nResult Check\n");
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		if(strcmp(emp[i].name, name) == 0){
			found = 1;
			printf("Employee ID: %d", emp[i].eid);
			printf("\nName: ");
			puts(emp[i].name);
			printf("Salary: %0.2f$\n", emp[i].salary);
			break;
		}
	}
	if(!found){
		printf("Name not invalid! Please try again.\n");
	}
}

// Hàm kiểm tra lương NV
void checkSalary(struct employee emp[]){
	printf("\nResult Check\n");
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		if(emp[i].salary > 3000){ // NV lương > 3000 thì hiển thị
			printf("Employee ID: %d", emp[i].eid);
			printf("\nName: ");
			puts(emp[i].name);
			printf("Salary: %0.2f$\n", emp[i].salary);
		}
	}	
}

// Hàm cập nhật thông tin NV theo ID
void updateEmployee(struct employee emp[], int id){
	int found = 0;
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		if(emp[i].eid == id){
			found = 1;
			printf("Enter new data to update: ");
			printf("\nEmployee Name: ");
			fflush(stdin);
			gets(emp[i].name);
			printf("Salary: ");
			scanf("%f", &emp[i].salary);
		}
	}
	if(!found){
		printf("ID not invalid! Please try again.\n");
	}
}

int main(){
	int choice;
	int n, id;
	char name[50];
	struct employee emp[MAX_EMPLOYEES];
	
	printf("\n\t\tMenu");
	printf("\n 1. Creat and Input Employee information");
	printf("\n 2. List all Employee");
	printf("\n 3. Search Employee by ID");
	printf("\n 4. Search Employee by Name");
	printf("\n 5. Display Employee whose salary > 3000");
	printf("\n 6. Update Employee");
	printf("\n 7. Exit");
	printf("\n====================================\n");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:

				creatEmployee(emp);
				break;
			case 2:
				printf("\nAll Employee: \n");
				displayAll(emp);
				printf("\n");
				break;
			case 3:
				printf("\nEnter ID of Employee to be search: ");
				scanf("%d", &id);
				findEmployeeById(emp, id);				
				break;
			case 4:
				printf("\nEnter name of Employee to be search: ");
				fflush(stdin);
				gets(name);
				findEmployeeByName(emp, name);
				break;
			case 5:
				checkSalary(emp);
				break;
			case 6:
				printf("\nEnter ID Employee to be update: ");
				scanf("%d", &id);
				updateEmployee(emp, id);
				break;
			case 7:
				printf("\nEnding program!\n");
				exit(0);
			default:
				printf("\nNot invalid! - Please try again.\n");
				printf("(Enter only from 1 to 7)\n");
				break;
		}
	}
	
	return 0;
}