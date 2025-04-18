#include <Windows.h>
#include <cstdint>

// ウィンドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
  // メッセージに応じてゲーム固有の処理を行う
  switch (msg) {
    // ウィンドウが破棄された
  case WM_DESTROY:
    // OSに対して、アプリの終了を伝える
    PostQuitMessage(0);
    return 0;
  }

  // 標準のメッセージ処理を行う
  return DefWindowProc(hwnd, msg, wparam, lparam);
}

// Windowsアプリでのエントリーポイント( main関数 )
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
  // 出力ウィンドウへの文字出力
  OutputDebugStringA("Hello,DirectX!\n");

  WNDCLASS wc{};
  // ウィンドウプロシージャ
  wc.lpfnWndProc = WindowProc;
  // 　ウィンドウクラス名(なんでもいい)
  wc.lpszClassName = L"CG2windowClass";
  // インスタンスハンドル
  wc.hInstance = GetModuleHandle(nullptr);
  // カーソル
  wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

  // ウィンドウクラスを登録する
  RegisterClass(&wc);

  // クライアントの領域のサイズ
  const int32_t kClintWidth = 1280;
  const int32_t kClintHeight = 720;

  // ウィンドウサイズを表す構造体にクライアント領域を入れる
  RECT wrc = {0, 0, kClintWidth, kClintHeight};

  // クライアント領域をもとに実際のサイズにwrcを変更してもらう
  AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

  // ウィンドウの生成
  HWND hwnd =
      CreateWindow(wc.lpszClassName,
                   L"CG2",
                   WS_OVERLAPPEDWINDOW, 
                   CW_USEDEFAULT,
                   CW_USEDEFAULT, 
                   wrc.right - wrc.left, 
                   wrc.bottom - wrc.top,
                   nullptr,
                   nullptr,
                   wc.hInstance,
                   nullptr);

  // ウィンドウを表示する
  ShowWindow(hwnd, SW_SHOW);

  MSG msg{};
  // ウィンドウの×ボタンが押されるまでループ
  while (msg.message != WM_QUIT) {
    // Windowsにメッセージが来てたら最優先で処理させる
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    } else {
      // ゲームの処理

    }
  }

  return 0;
}