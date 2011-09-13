<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="fi_FI">
<context>
    <name>HelpPage</name>
    <message>
        <location filename="qmldir/HelpPage.qml" line="31"/>
        <source>Copyright (C) %1 %2</source>
        <translation>Copyright (C) %1 %2</translation>
    </message>
    <message>
        <location filename="qmldir/HelpPage.qml" line="37"/>
        <source>Nokia N9 dedicates some RAM for use as in-memory compressed swap space. SwapStat allows you to get access to the kernel based statistics provided for the swap device.</source>
        <translation>Nokia N9 varaa osan keskusmuistista pakattua heittovaihtotiedostoa varten. SwapStat raportoi käyttöjärjestelmän ytimen tilastotietoja heittovaihtojärjestelmän toiminnasta.</translation>
    </message>
    <message>
        <location filename="qmldir/HelpPage.qml" line="42"/>
        <source>The device node that provides the compressed swap is &lt;tt&gt;/dev/ramzswap0&lt;/tt&gt;. SwapStat uses the &lt;tt&gt;RZSIO_GET_STATS&lt;/tt&gt; &lt;tt&gt;ioctl&lt;/tt&gt; call to query the statistics.</source>
        <translation>Heittovaihtojärjestelmän tiedostopolku on &lt;tt&gt;/dev/ramzswap0&lt;/tt&gt;. SwapStat käyttää &lt;tt&gt;RZSIO_GET_STATS&lt;/tt&gt; &lt;tt&gt;ioctl&lt;/tt&gt;-kutsua tilastotietojen kyselyyn.</translation>
    </message>
</context>
<context>
    <name>MainPage</name>
    <message>
        <location filename="qmldir/MainPage.qml" line="26"/>
        <source>About</source>
        <translation>Tietoja ohjelmasta</translation>
    </message>
    <message>
        <location filename="qmldir/MainPage.qml" line="36"/>
        <source>Overview</source>
        <translation>Yleisnäkymä</translation>
    </message>
    <message>
        <location filename="qmldir/MainPage.qml" line="40"/>
        <source>Details</source>
        <translation>Yksityiskohdat</translation>
    </message>
</context>
<context>
    <name>ZBasicTab</name>
    <message>
        <location filename="qmldir/ZBasicTab.qml" line="21"/>
        <source>Swap Compression Factor:</source>
        <translation>Pakkauskerroin:</translation>
    </message>
    <message>
        <location filename="qmldir/ZBasicTab.qml" line="44"/>
        <source>Original data size: &lt;b&gt;%1&lt;/b&gt;MB</source>
        <oldsource>&lt;b&gt;%1&lt;/b&gt;MB compressed to &lt;b&gt;%2&lt;/b&gt;MB</oldsource>
        <translation>Koko ennen pakkausta: &lt;b&gt;%1&lt;/b&gt;MB</translation>
    </message>
    <message>
        <location filename="qmldir/ZBasicTab.qml" line="54"/>
        <source>Compressed data size: &lt;b&gt;%1&lt;/b&gt;MB</source>
        <translation>Koko pakattuna: &lt;b&gt;%1&lt;/b&gt;MB</translation>
    </message>
    <message>
        <location filename="qmldir/ZBasicTab.qml" line="62"/>
        <source>Swap type: &lt;b&gt;Disk Backed&lt;/b&gt;</source>
        <translation>Tyyppi: &lt;b&gt;Levypohjainen&lt;/b&gt;</translation>
    </message>
    <message>
        <location filename="qmldir/ZBasicTab.qml" line="63"/>
        <source>Swap type: &lt;b&gt;In-Memory&lt;/b&gt;</source>
        <oldsource>Swap type: &lt;b&gt;In-Memory&lt;/b&gt;&lt;</oldsource>
        <translation>Tyyppi: &lt;b&gt;Keskusmuistipohjainen&lt;/b&gt;</translation>
    </message>
</context>
<context>
    <name>ZRamInfoModel</name>
    <message>
        <location filename="ZRamInfoModel.cpp" line="100"/>
        <source>Backing swap: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="101"/>
        <source>Memory limit: %1 MB</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="102"/>
        <source>Disk size: %1 MB</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="103"/>
        <source>Reads: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="104"/>
        <source>Writes: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="105"/>
        <source>Failed reads: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="106"/>
        <source>Failed writes: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="107"/>
        <source>Invalid I/O requests: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="108"/>
        <source>Free notification slots: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="109"/>
        <source>Zero filled pages: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="110"/>
        <source>Well compressed pages: %1 %</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="111"/>
        <source>Incompressible pages: %1 %</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="112"/>
        <source>Pages stored: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="113"/>
        <source>Pages used: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="114"/>
        <source>Original data size: %1 MB</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="115"/>
        <source>Compressed data size: %1 MB</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="116"/>
        <source>Memory used total: %1 MB</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="117"/>
        <source>Backing device reads: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="ZRamInfoModel.cpp" line="118"/>
        <source>Backing device writes: %1</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
