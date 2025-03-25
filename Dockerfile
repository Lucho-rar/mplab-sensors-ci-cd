FROM ubuntu:18.04

RUN dpkg --add-architecture i386 && apt-get update && \
  apt-get install -y libc6:i386 libx11-6:i386 libxext6:i386 libstdc++6:i386 libexpat1:i386 wget sudo make && \
  rm -rf /var/lib/apt/lists/*


RUN pip install gdown

# Instalar el compilador XC8
RUN wget -nv -O /tmp/xc8.run http://ww1.microchip.com/downloads/en/DeviceDoc/xc8-v2.50-full-install-linux-installer.run && \
  chmod +x /tmp/xc8.run &&  \
  /tmp/xc8.run --mode unattended --unattendedmodeui none --netservername localhost --LicenseType FreeMode --prefix /opt/microchip/xc8/v2.50 && \
  rm /tmp/xc8.run

# Instalar MPLAB X
RUN wget -nv -O /tmp/mplabx.tar http://ww1.microchip.com/downloads/en/DeviceDoc/MPLABX-v6.00-linux-installer.tar && \
  cd /tmp && tar -xf /tmp/mplabx.tar && rm /tmp/mplabx.tar && \
  mv MPLAB*-linux-installer.sh mplabx && \
  sudo ./mplabx --nox11 -- --unattendedmodeui none --mode unattended --ipe 0 --collectInfo 0 --installdir /opt/mplabx && \
  rm mplabx

COPY build.sh /build.sh

ENTRYPOINT [ "/build.sh" ]
