---
name: リリース
about: 新しいバージョンのリリース手順
title: '[Release] v'
labels: 'release'
assignees: ''

---

**リリースバージョン**
v0.0.0

**主な変更点**
- 機能追加:
- バグ修正:
- 改善:

## リリース前チェック

- [ ] すべてのサブモジュールが正しいブランチ (scarthgap) を指している
- [ ] ビルドが正常に完了する (`bitbake core-image-minimal`)
- [ ] 生成されたイメージが Raspberry Pi 4 で正常に起動する
- [ ] CHANGELOG.md が更新されている
- [ ] README.md のバージョン情報が更新されている

## ビルド検証

- [ ] `build/tmp/deploy/images/raspberrypi4-64/` にイメージが生成されている
- [ ] .wic または .wic.bz2 ファイルが存在する
- [ ] イメージサイズが想定範囲内である

## リリース手順

- [ ] Git タグを作成: `git tag -a v<version> -m 'Release v<version>'`
- [ ] タグをプッシュ: `git push origin v<version>`
- [ ] GitHub Release を作成し、リリースノートを記載
- [ ] ビルド成果物 (.wic.bz2) を Release に添付
- [ ] リリース通知を関係者に送信

## リリース後確認

- [ ] GitHub Release ページが正しく表示される
- [ ] ダウンロードリンクが有効である
- [ ] 次バージョンの開発ブランチを作成（必要に応じて）

**備考**
特記事項があれば記載してください。
