class Png2aa < Formula
  desc ""
  homepage "https://github.com/shumon84/png2aa"
  url "https://github.com/shumon84/png2aa/archive/v1.1.tar.gz"
  version "1.1"
  sha256 "636c4f388dc541b6a15e201d62d45131ae85be931f8f29b56d65d0a5286f29c2"

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
