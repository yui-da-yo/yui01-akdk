# オートマウス機能を有効化
POINTING_DEVICE_AUTO_MOUSE_ENABLE = yes
# VIAL上でのオートマウス設定を有効化
VIAL_AUTO_MOUSE_ENABLE = yes
# VIALのレイヤー切り替え機能を有効化
VIAL_AUTO_MOUSE_LAYER_ENABLE = yes

# マウスキー機能（キー入力でのマウス操作）を有効化
MOUSEKEY_ENABLE = yes

# VIA設定機能を有効化
VIA_ENABLE = yes
# VIAL設定機能を有効化
VIAL_ENABLE = yes
# VIALのセキュリティロックを無効化（設定保存を容易にする）
VIAL_INSECURE = yes

# ポインティングデバイス機能を全体的に有効化
POINTING_DEVICE_ENABLE = yes
# ポインティングデバイスのドライバをカスタム設定に指定
POINTING_DEVICE_DRIVER = custom
# 使用するセンサー（paw3222）のソースファイルを追加
SRC += paw3222.c
