{ pkgs }: {
  deps = [
    pkgs.python38Packages.conda
    pkgs.nano
    pkgs.powershell
    pkgs.toybox
    pkgs.mkinitcpio-nfs-utils
    pkgs.openssh_with_kerberos
    pkgs.wget
    pkgs.vim
    pkgs.arcan.ffmpeg
    pkgs.ffmpeg.bin
    pkgs.yt-dlp
    pkgs.killall
    pkgs.python38Full
    pkgs.clang_12
    pkgs.ccls
    pkgs.gdb
    pkgs.gnumake
  ];
  env = {
    PYTHON_LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath ([
      # Needed for pandas / numpy
      pkgs.stdenv.cc.cc.lib
      pkgs.zlib
      # Needed for matplotlib
      pkgs.xorg.libX11
      # Needed for pygame
      pkgs.glib
    ] ++ (with pkgs.xlibs; [ libX11 libXext libXinerama libXcursor libXrandr libXi libXxf86vm ]));
    PYTHONBIN = "${pkgs.python38Full}/bin/python3.8";
    LANG = "en_US.UTF-8";
  };
}