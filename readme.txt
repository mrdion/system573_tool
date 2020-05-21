*各項目の概要
INPUT CHECK <-入力テスト
INPUT TIMING CHECK <-1フレームごとの入力ログ
FLASH CHECK <-ONBOARD FLASHなどの中身確認
SIO CHECK <-シリアルポート経由で入力されたバイナリをオウム返しする
UTIL RTC <-RTC周りの設定など(正常に動かない)


*接続方法
カセットのNETWORK 1(Tx) 2(Rx) 5(GND)からPCのRS232Cポートにつなぐ


*カセット部の作成
ピンについてはcass_pin.pngを参考に。

信号は下のような形で出力されています。
マザーボード->10Ω抵抗->74LS07->4.7kΩでプルアップ->フォトカプラ(PC9D10)->RS232Cドライバ->ポート

使われているドライバICなど
AD232FL(GF2 シルク)
ADM232LJR
ADM232AARN(dm2 シルク)
LT1381CS(dm2 実装)

