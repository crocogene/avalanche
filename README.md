# Раскладка для клавиатуры Avalanche v4.2
На основе раскладки Ильи Шепрута [Читать статью](https://optozorax.github.io/p/my-keyboard-layout/)

# Железные особенности моего варианта клавиатуры

# Сборка и прошивка (linux)
cd ~
git clone https://github.com/qmk/qmk_firmware.git
git clone https://github.com/crocogene/avalanche.git
ln -s ~/avalanche ~/qmk_firmware/keyboards/avalanche/v4/keymaps/crocozorax
cd qmk_firmware
patch -ruN -d quantum < ~/avalanche/quantum.patch
make avalanche/v4:crocozorax
