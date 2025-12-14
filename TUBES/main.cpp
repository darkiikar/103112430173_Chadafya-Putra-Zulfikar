#include <iostream>
#include "./include/auth.hpp"
using namespace std;

int main() {
    addrUser root = NULL;
    addrUser currentUser = NULL;

    int choice;

    do {
        cout << "\n=== TEST REGISTER & LOGIN ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Lihat jumlah user (test)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(root);
                break;

            case 2:
                currentUser = loginUser(root);
                break;

            case 3:
                cout << "Total user: " << countUsers(root) << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}

#include "./include/post.hpp"


### Menu User

cpp
void userMenu(addrUser currentUser) {
    int choice, postId = 1;
    string content;

    do {
        cout << "\n=== MENU USER ===\n";
        cout << "1. Buat Postingan\n";
        cout << "2. Lihat Postingan Saya\n";
        cout << "3. Hapus Postingan\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Isi postingan: ";
                getline(cin, content);
                addPost(currentUser->firstPost, postId++, content);
                cout << "Postingan berhasil dibuat" << endl;
                break;

            case 2:
                viewPosts(currentUser->firstPost);
                break;

            case 3:
                int id;
                cout << "ID Post: ";
                cin >> id;
                deletePost(currentUser->firstPost, id);
                break;
        }
    } while (choice != 0);
}


### Panggil di main()

cpp
case 2:
    currentUser = loginUser(root);
    if (currentUser != NULL) {
        userMenu(currentUser);
    }
    break;


Tambahkan menu admin:

cpp
case 4:
    showTimeline(root);
    break;