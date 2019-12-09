from distutils.core import setup, Extension

def main():
    setup(ext_modules=[Extension("SimpleMath", ["extend.c"])])

if __name__ == "__main__":
    main()