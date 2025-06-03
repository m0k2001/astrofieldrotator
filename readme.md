Remix from different projects :

https://www.scopefocus.info/home/rotator
<br>
https://www.thingiverse.com/thing:5253710
<br>
https://www.thingiverse.com/thing:5243794
<br>

You can use different motor options. 2 PCB and box heights if you solder Arduino Nano board directly on PCB or if you use pin headers to keep it removable.
Backfocus length is about 25mm.
It works perfectly fine with [ASCOM driver](https://drive.google.com/file/d/1Zqj4HnF0sWtz7hacBCAIt85_bKwMDyPM/view?usp=drive_web) (I personnaly use [N.I.N.A](https://nighttime-imaging.eu/) flawlessly).
Ther's also a [Windows App](https://drive.google.com/file/d/1RpfXV0fqB5MPrnLDqRJleW-3eae0BWBA/view?usp=drive_web) to test teh device.

I improved some details :
- better/stronger holding of the ring
- PCB box
- PCB design :
    - added a microswicth to reverse rotation (Arduino must be restarted for change to be effective)
    - added an optional DC buck converter to power Arduino Nano
    - different motor/pulley options
    - increased GT2 ring : 144 teeth
    - Arduino formware : MS1, MS2, MS3 are software defined. Rotation speed/acceleration modified.
- added M48 and M54 design compatibility

BOM Electronics :
- Arduino Nano (chinese clone works well)
- [Green A4988 Stepper Driver](https://fr.aliexpress.com/item/1005006096236486.html?spm=a2g0o.productlist.main.8.791e3ee0x2Wejk&aem_p4p_detail=202506010202186818268424725510002111803&algo_pvid=7a1784a4-9744-448c-bee4-7cddd74eeb53&algo_exp_id=7a1784a4-9744-448c-bee4-7cddd74eeb53-7&pdp_ext_f=%7B%22order%22%3A%2276%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21EUR%211.37%211.37%21%21%2110.91%2110.91%21%402103867617487685385324645e6d48%2112000035721699088%21sea%21FR%213635870101%21X&curPageLogUid=JKusflGrCwJZ&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202506010202186818268424725510002111803_2) Please take care to finely adjust Vref according to motor model : 0,85V for NEMA 17 HS4401, 0,56V for NEMA 17HS08 and NEMA 14 (Galileo 2 kit)
- (optional) [Female 2.54 Breakable Pin Header Connector Strip](https://fr.aliexpress.com/item/32993182990.html?spm=a2g0o.order_list.order_list_main.99.381f5e5bU6l48Z&gatewayAdapt=glo2fra)
- [JST XH 4pins female for PCB](https://fr.aliexpress.com/item/1005003422202370.html?spm=a2g0o.productlist.main.4.733c123e123eIp&aem_p4p_detail=202506010201514339813061075800002537197&algo_pvid=ce47df3f-900f-4b5d-bcdf-438aafe58a9d&algo_exp_id=ce47df3f-900f-4b5d-bcdf-438aafe58a9d-3&pdp_ext_f=%7B%22order%22%3A%222127%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21EUR%211.30%211.23%21%21%211.44%211.36%21%40211b618e17487685111562397e07c5%2112000027276250001%21sea%21FR%213635870101%21X&curPageLogUid=zPfz1wz6K1ms&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202506010201514339813061075800002537197_1)
- [5,5/2,1 DC Plug](https://fr.aliexpress.com/item/32872192541.html?spm=a2g0o.order_list.order_list_main.326.10785e5bllgH6n&gatewayAdapt=glo2fra)
- [Mini Switch SPDT](https://fr.aliexpress.com/item/4000042632226.html?spm=a2g0o.order_list.order_list_main.58.10785e5bllgH6n&gatewayAdapt=glo2fra)
- [Electrolytic capacitor 100uF - 16v minimum](https://fr.aliexpress.com/item/1005005558643765.html?spm=a2g0o.productlist.main.4.7733650dndkFgK&aem_p4p_detail=2025060305001214367913890144880005565257&algo_pvid=be663ffa-9815-4268-9c28-af99f5bdd686&algo_exp_id=be663ffa-9815-4268-9c28-af99f5bdd686-3&pdp_ext_f=%7B%22order%22%3A%22684%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21EUR%211.28%211.28%21%21%211.43%211.43%21%40211b628117489520127128549e19eb%2112000033538166697%21sea%21FR%213635870101%21X&curPageLogUid=BbOlFtO9EoH9&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=2025060305001214367913890144880005565257_1)
- [(optional) Buck Converter 9V](https://fr.aliexpress.com/item/1005007342634171.html?spm=a2g0o.order_list.order_list_main.106.20895e5bOiKojo&gatewayAdapt=glo2fra)
- USB cable
- DC 5.5/2.1 12V Power Source if needed

BOM Motion :
- Stepper Motor (3 otpions):
    - [NEMA 17 42mm or 44mm](https://fr.aliexpress.com/item/1005001303445983.html?spm=a2g0o.productlist.main.4.20d427b31qxGxm&aem_p4p_detail=202506030448011352536900570520003778984&algo_pvid=9c4a57d1-3508-4f53-8bb7-7d7ab55c7ab2&algo_exp_id=9c4a57d1-3508-4f53-8bb7-7d7ab55c7ab2-3&pdp_ext_f=%7B%22order%22%3A%22123%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21EUR%2111.79%2111.79%21%21%2113.16%2113.15%21%402103835c17489512811927965e2491%2112000015638300802%21sea%21FR%213635870101%21X&curPageLogUid=UG3BMvaVRvPK&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202506030448011352536900570520003778984_1)
    - [NEMA 17 pancake](https://fr.aliexpress.com/item/1005005742670433.html?spm=a2g0o.order_list.order_list_main.22.20895e5bfEFmwY&gatewayAdapt=glo2fra)
    - [Galileo 2 extruder kit](https://fr.aliexpress.com/item/1005007811125592.html?spm=a2g0o.order_list.order_list_main.5.7efb5e5bMKatdZ&gatewayAdapt=glo2fra)
- [6mm GT2 Belt 348mm or 350mm](https://fr.aliexpress.com/item/1005003420210494.html?spm=a2g0o.order_list.order_list_main.93.20895e5bfEFmwY&gatewayAdapt=glo2fra)
- [Rotation ring (42, 48 or 54mm)](https://fr.aliexpress.com/item/33018620597.html?spm=a2g0o.order_list.order_list_main.148.20895e5bfEFmwY&gatewayAdapt=glo2fra)
- [GT2 pulley - W6B5 - 16 or 20 teeth](https://fr.aliexpress.com/item/1005001933418605.html?spm=a2g0o.order_list.order_list_main.36.20895e5bOiKojo&gatewayAdapt=glo2fra)
- [M2.53 Brass Inserts OD 3.5 Length 4mm](https://fr.aliexpress.com/item/1005004535859664.html?spm=a2g0o.order_list.order_list_main.67.20895e5bOiKojo&gatewayAdapt=glo2fra)
- [M2 Brass Inserts OD 3.2 Length 3mm](https://fr.aliexpress.com/item/1005003582355741.html?spm=a2g0o.order_list.order_list_main.72.20895e5bOiKojo&gatewayAdapt=glo2fra)
- M2, M2.5 and M3 screws, M3 washers
- Square Nut M3 5mm

Tools :
- 3D Printer (I recommend at least ABS/ASA, but PETG-CF is way more rigid - PLA is not suitable)
- Solder Iron
- Arduino IDE to flash [firmware](https://github.com/m0k2001/astrofieldrotator/tree/main/Arduino/ArduinoRotatorFirmware_ver1008_switch)
- Multimeter

Her is a summary of different motor options (steps per degree is a parameter you must define in ASCOM driver options) :
| Motor model          | 17HS08-1004S | 17HS08-1004S | 17HS4001 | 17HS4001 | Nema36 + Planetary  |
|----------------------|--------------|--------------|----------|----------|---------------------|
| Pulley Teeth         | 16           | 20           | 16       | 20       | 20                  |
| Torque (N.cm)        | 144          | 115          | 378      | 302      | 648                 |
| Rel. motor thickness | 0            | 0            | + 20mm   | + 20mm   | + 18mm              |
| Steps / degree       | 80           | 64           | 80       | 64       | 576                 |
| Precision (degre)    | 1/5          | 1/4          | 1/5      | 1/4      | 1/36                |
| Precision (arcsec)   | 720          | 900          | 720      | 900      | 100                 |
| Price                | +            | +            | +        | +        | ++                  |

Using planetary gearbox NEMA 36 and 54mm rotation ring should not cost more than 120€, without 3D printing and power source.

Just to give a comparison, Zwo CAA is 399€, 25 N.cm torque, precision < 0,1° ( < 360 arcsec). But thickness is less important (17,5mm).
