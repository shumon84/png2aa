class Png2aa < Formula
  desc ""
  homepage "https://github.com/shumon84/png2aa"
  url "https://github.com/shumon84/png2aa/archive/v1.2.tar.gz"
  version "1.2"
  sha256 "166e93d543165bcf32462564353e13d167b5d098451cb8641fed3a2e5ef324e9"

  depends_on "libpng"
  depends_on "jpeg"

  def install
    system "make"
    bin.install "png2aa"
  end

  test do
    system "#{bin}/png2aa", "test"
  end
end
