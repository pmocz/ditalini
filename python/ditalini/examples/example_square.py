# This is an example of how to our the ditalini package
# Philip Mocz (2024)
#
# Install with:
#   pip install ditalini

import ditalini


def main():

    sim = ditalini.Simulation(17)
    print("The square of 17 is", sim.square())


if __name__ == '__main__':
    main()
