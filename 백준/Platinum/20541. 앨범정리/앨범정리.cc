#include <iostream>
#include <set>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

struct NODE
{
    NODE *parent;
    string name;
    set<string> photo;
    map<string, NODE *> child;
};

NODE *make_node()
{
    NODE *Node = new NODE();
    Node->parent = NULL;
    return Node;
}

NODE *root;
NODE *cur;

pair<int, int> delete_album(NODE *Node)
{
    int deleted_album = 1;
    int deleted_photo = Node->photo.size();

    for (auto it = Node->child.begin(); it != Node->child.end(); it++)
    {
        pair<int, int> deleted = delete_album((*it).second);

        deleted_album += deleted.first;
        deleted_photo += deleted.second;
    }

    return {deleted_album, deleted_photo};
}

// 현재 앨범에 속해있는 앨범 중 동일한 이름 있으면 출력, 그렇지 않으면 생성
void mkalb()
{
    string album;
    cin >> album;

    if (cur->child.find(album) != cur->child.end())
    {
        cout << "duplicated album name" << endl;
    }
    else
    {
        NODE *temp = make_node();
        temp->name = album;
        temp->parent = cur;
        cur->child.insert({album, temp});
    }
}

// 삭제된 앨범의 개수와 시진의 개수를 공백으로 구분하여 출력
void rmalb()
{
    string cmd;
    cin >> cmd;

    // 현재 앨범에 속해있는 앨범이 존재한다면, 이름이 사전 순으로 가장 빠른 앨범 삭제
    if (cmd == "-1")
    {
        if (cur->child.size() > 0)
        {
            auto it = cur->child.begin();
            pair<int, int> deleted = delete_album((*it).second);
            cout << deleted.first << " " << deleted.second << "\n";
            cur->child.erase(it);
        }
        else
        {
            cout << 0 << " " << 0 << "\n";
        }
    }
    else if (cmd == "0")
    {

        if (cur->child.size() > 0)
        {
            pair<int, int> deleted = {0, 0};
            for (auto it = cur->child.begin(); it != cur->child.end(); it++)
            {
                pair<int, int> temp = delete_album((*it).second);
                deleted.first += temp.first;
                deleted.second += temp.second;
            }
            cout << deleted.first << " " << deleted.second << "\n";
            cur->child.clear();
        }
        else
        {
            cout << 0 << " " << 0 << "\n";
        }
    }
    else if (cmd == "1")
    {
        if (cur->child.size() > 0)
        {
            auto it = cur->child.end();
            it--;
            pair<int, int> deleted = delete_album((*it).second);
            cout << deleted.first << " " << deleted.second << "\n";
            cur->child.erase(it);
        }
        else
        {
            cout << 0 << " " << 0 << "\n";
        }
    }
    else
    {
        if (cur->child.find(cmd) != cur->child.end())
        {
            auto it = cur->child.find(cmd);
            pair<int, int> deleted = delete_album((*it).second);
            cout << deleted.first << " " << deleted.second << "\n";
            cur->child.erase(it);
        }
        else
        {
            cout << 0 << " " << 0 << "\n";
        }
    }
}

// 현재 앨범에 속해있는 사진 중에 동일한 이름을 가진 사진이 존재하여 사진이 삽입되지 않았으면 출력. 그렇지 않으면 삽입
void insert()
{
    string photo;
    cin >> photo;

    if (cur->photo.find(photo) != cur->photo.end())
    {
        cout << "duplicated photo name" << endl;
    }
    else
    {
        cur->photo.insert(photo);
    }
}

// 삭제된 사진의 개수 출력
void delete_photo()
{
    string cmd;
    cin >> cmd;

    int cnt = 0;

    if (cmd == "-1")
    {
        if (cur->photo.size() > 0)
        {
            cnt++;
            auto it = cur->photo.begin();
            cur->photo.erase(it);
        }
    }
    else if (cmd == "0")
    {
        if (cur->photo.size() > 0)
        {
            for (auto it = cur->photo.begin(); it != cur->photo.end(); it++)
            {
                cnt++;
            }
            cur->photo.clear();
        }
    }
    else if (cmd == "1")
    {
        if (cur->photo.size() > 0)
        {
            auto it = cur->photo.end();
            it--;
            cur->photo.erase(it);
            cnt++;
        }
    }
    else
    {
        if (cur->photo.find(cmd) != cur->photo.end())
        {
            auto it = cur->photo.find(cmd);
            cur->photo.erase(it);
            cnt++;
        }
    }

    cout << cnt << "\n";
}

// 현재 앨범 이름을 출력
void ca()
{
    string cmd;
    cin >> cmd;

    if (cmd == "..")
    {
        if (cur->name != "album")
        {
            cur = cur->parent;
        }
    }
    else if (cmd == "/")
    {
        cur = root;
    }
    else
    {
        if (cur->child.find(cmd) != cur->child.end())
        {
            auto it = cur->child.find(cmd);
            cur = (*it).second;
        }
    }

    cout << cur->name << "\n";
}

int main()
{
    FASTIO();
    cin >> N;

    root = make_node();
    root->name = "album";
    cur = root;

    for (int i = 1; i <= N; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "mkalb")
        {
            mkalb();
        }
        else if (cmd == "rmalb")
        {
            rmalb();
        }
        else if (cmd == "insert")
        {
            insert();
        }
        else if (cmd == "delete")
        {
            delete_photo();
        }
        else if (cmd == "ca")
        {
            ca();
        }
    }

    return 0;
}