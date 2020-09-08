# MiniWebServer
## 一个简版的高并发Web服务器

自己做的一个简版的高并发Web服务器demo，目前只能处理GET请求
- 使用Epoll边沿触发的IO多路复用技术，非阻塞IO
- 使用多线程充分利用多核CPU，并使用线程池避免线程频繁创建销毁的开销
- 主线程只负责监听和accept请求，其他IO操作全部由子线程（工作线程）完成
- 在我的渣机虚拟机上用WebBench测压，在2000并发量的时候能保持极低的出错率，QPS为3000左右（我太菜了(┬＿┬)）