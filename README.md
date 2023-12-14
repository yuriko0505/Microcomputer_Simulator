# VSCode でマイコンをシミュレートする話

記事へのリンク → [VSCode でマイコンをシミュレートする話](https://qiita.com/yuimyun_hykook/items/0c44fa03ecc88177e04e)

## 準備
このプロジェクトを実行するために以下のツールが必要です:
- VSCode
- PlatformIO
- Wokwi
- g++
- make コマンド

## 使い方
```
$ make <project>
```
このコマンドで、シミュレーションに必要なオブジェクトを生成できます。

その後、`F1` キーで `Wokwi: Start Simulation` してください。

## シミュレーションできるもの一覧
- `led` : Lチカ
- `tact` : スイッチ
- `buz` : ブザー
- `time` : 時刻表示
- `ldr` : 照度センサー
- `pir` : 人感センサー
